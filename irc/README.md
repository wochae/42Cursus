# irc

## 프로젝트 개요
- C++98로 구현된 이벤트 기반 IRC 서버입니다.
- macOS/BSD의 `kqueue`로 소켓 다중 입출력을 처리하고, 세션/클라이언트/채널/패킷을 모듈로 분리했습니다.
- 인증(`PASS`), 닉네임/유저 등록(`NICK`, `USER`), 채널 관리(`JOIN`, `PART`, `TOPIC`, `MODE`, `INVITE`, `KICK`), 메시지 전송(`PRIVMSG`, `NOTICE`), 연결 종료(`QUIT`) 등 핵심 IRC 동작을 지원합니다.

## 빌드
- 요구 환경: macOS 또는 BSD 계열(OS X의 `kqueue` 사용), `c++` 컴파일러
- 표준: 서버는 `-std=c++98`로 빌드됩니다.
- 명령:
  - `make` → 서버 바이너리 `ircserv` 생성
  - `make clean`, `make fclean`, `make re` 지원

## 실행
- 사용법: `./ircserv <port> <password>`
- 예시:
```bash
./ircserv 6667 secret
```
- 포트: 숫자 문자열로 전달됩니다(예: `6667`).
- 비밀번호: 클라이언트는 `PASS <password>`를 먼저 전송해야 하며, 실패 시 이후 `NICK`/`USER`가 거부됩니다.

## 빠른 테스트(예: netcat)
- 서버 실행 후, 다른 터미널에서 `nc -v localhost 6667`로 접속합니다.
- 각 줄은 `\r\n` 종결을 사용해야 합니다. 예시 입력 흐름:
  - `PASS secret`
  - `NICK alice`
  - `USER alice host server :Alice Name`
  - `JOIN #room`
  - `PRIVMSG #room :hello world`
  - `QUIT :bye`
- 서버는 일부 숫자 응답 코드(예: `001`, `432`, `433`, `461`, `462`, `464`)와 브로드캐스트를 사용합니다.

## 지원 명령
- 인증/등록
  - `PASS <password>`: 서버 비밀번호 검증. 성공 시 이후 명령 허용.
  - `NICK <nickname>`: 닉네임 등록/변경. 유효성, 중복 검사 포함.
  - `USER <username> <hostname> <servername> :<realname>`: 사용자 정보 등록.
  - `PING <token>`: 핑-퐁(연결 확인).
- 채널/유저 관리
  - `JOIN <channel>[,<channel>...] [<key>]`: 채널 참가, 키 기반 접근 처리.
  - `PART <channel>`: 채널 떠나기.
  - `TOPIC <channel> [<topic>]`: 채널 토픽 조회/설정.
  - `MODE <channel> <modes> [<params>...]`: 채널 모드 변경(예: 권한/제한).
  - `INVITE <nick> <channel>`: 유저 초대.
  - `KICK <channel> <nick> [:reason]`: 유저 강퇴.
- 메시지
  - `PRIVMSG <target> :<message>`: 채널 또는 유저에게 메시지.
  - `NOTICE <target> :<message>`: 공지 메시지(응답 없이 전송).
- 종료
  - `QUIT [:message]`: 연결 종료(리소스 정리).

## 아키텍처 개요
- `srcs/server/IRCServer.*`
  - 초기화(`init(port, password)`): `ServerSocket` 바인드/리스닝, `PacketManager`에 비밀번호 설정, `SocketReactor` 핸들러 등록.
  - 실행(`start()`): 이벤트 루프에서 `SocketReactor.run()` → `process()`로 수신 패킷 처리.
  - 이벤트 핸들러:
    - 새 연결 수락 후 `O_NONBLOCK` 설정, `SessionManager`에 등록, 리액터에 소켓 추가.
    - 클라이언트 소켓에서 읽기 가능 이벤트 시 해당 `Session::onReadable()` 호출.
    - 에러/EOF 시 `QUIT` 처리와 세션 해제.
- `srcs/reactor/SocketReactor.{hpp,tpp}`
  - `kqueue` 기반 리액터 구현. `EVFILT_READ`에서 성공 핸들러 호출, `EV_ERROR`/`EVFILT_WRITE`에서 에러 핸들러 호출, `EV_EOF`에서 소켓 제거.
- `srcs/session/Session.*`
  - 비블로킹 수신 버퍼링, `\r\n` 기준 메시지 단위 파싱(`IRCMessage::parse`) 후 서버의 패킷 큐로 전달.
  - `sendPacket()`로 응답 전송.
- `srcs/packet/PacketManager.*`
  - 명령 디스패치 테이블 구성(`PASS`, `NICK`, `USER`, `PING`, `JOIN`, `PART`, `TOPIC`, `PRIVMSG`, `NOTICE`, `QUIT`, `KICK`, `MODE`, `INVITE`).
  - 클라이언트/채널 매니저와 협업, 브로드캐스트/개별 전송 처리.
- `srcs/client/*`, `srcs/channel/*`
  - 유저 상태, 닉네임 관리, 채널 참여/탈퇴/토픽/모드/초대/강퇴 등 로직 분리.

## 처리 흐름
1. 클라이언트 연결 수락 → 세션 등록 → 리액터에 소켓 등록.
2. 읽기 이벤트 수신 → `Session::onReadable()`에서 버퍼 파싱 → `IRCMessage`들 생성.
3. 서버 패킷 큐(`IRCServer::_packetQueue`)에 적재 → `IRCServer::process()`에서 `PacketManager`로 전달.
4. 명령 처리 후 응답 전송 및 채널 브로드캐스트/리소스 해제 수행.

## 테스트 폴더(`./test`)
- `parse.cpp`: 간단한 IRC 메시지 파서 예제(C++11).
- 빌드/실행:
  - `cd test && make`
  - 생성된 실행 파일 이름은 동일하게 `ircserv`입니다(서버와 다른 디렉터리이므로 충돌 없음).
  - 샘플 입력들을 파싱하여 콘솔에 구조를 출력합니다.

## 주의 사항
- OS 의존성: `kqueue` 사용으로 macOS/BSD에서 실행됩니다(Linux의 `epoll`과 비호환).
- 입력 라인 종결: 모든 명령은 `\r\n`으로 종료해야 정상 파싱됩니다.
- 인증 순서: `PASS` 없이 `NICK`/`USER`를 시도하면 인증 실패(`ERROR Authentication failed`) 응답 또는 거부가 발생합니다.

## 라이선스/기여
- 42 프로젝트 학습 목적의 구현입니다. 이슈/PR 템플릿은 `.github/` 폴더에서 확인하세요.