# 42Cursus Workspace

이 저장소는 42 커리큘럼의 핵심 C 과제들을 순차적으로 구현하고, 각 과제를 서로 재사용하도록 구성한 워크스페이스입니다. `libft`로 시작해 문자열/메모리/리스트 유틸을 라이브러리로 정리하고, 이를 바탕으로 `get_next_line`, `ft_printf`, `push_swap`, `so_long`, `minitalk` 등으로 학습을 확장합니다.

## 빌드와 실행: Make를 사용하는 이유
- 각 폴더에서 `make`로 빌드하며, 공통적으로 `clean`, `fclean`, `re`, `bonus` 타겟을 제공합니다.
- 정적 라이브러리(`.a`)는 `ar`로 아카이빙합니다. 예: `libft/Makefile`의 `$(AR) $(ARFLAGS)`.
- 링킹은 `-L <libdir> -l<name>` 패턴을 사용합니다. 예: `push_swap/Makefile`에서 `-L ./libft -lft`.
- macOS 기준 실행 예:
  - `libft`: `make` → `libft.a` 생성
  - `ft_printf`: `make` → `libftprintf.a` 생성
  - `push_swap`: `make` → `./push_swap` 실행 파일 생성
  - `minitalk`: `make` → `./server`, `./client` 생성
  - `so_long`: `make` → `./so_long` 생성 (외부 `mlx` 포함)
  - `get_next_line`: 과제 성격상 단독 실행 파일 대신 예제/테스트로 사용

## C 기본: 컴파일과 링크 파이프라인
- 전처리 → 컴파일 → 어셈블 → 링킹의 단계로 진행합니다.
- 헤더(`.h`) 선언과 구현(`.c`)을 분리해 재사용성을 높입니다.
- 링커는 심볼 해석과 라이브러리 결합을 수행하며, 정적 라이브러리(`.a`)는 빌드 시 코드가 바이너리에 포함됩니다.

## printf 이전: 왜 write를 사용했는가
- `write(int fd, const void *buf, size_t count)`는 커널의 파일 디스크립터(FD)에 직접 쓰는 시스템 콜로, 포맷팅 없이 바이트를 그대로 출력합니다.
- `printf`는 사용자 공간의 표준 라이브러리(`stdio`) 버퍼링과 포맷 파싱, 가변인자 해석이 필요합니다. 42 초기 과제에서는 표준 라이브러리 사용이 제한되므로 `write`가 적합합니다.
- 특징:
  - 포맷팅이 없어 제어가 단순합니다.
  - 반환값은 실제 기록한 바이트 수로, 오류 처리가 명확합니다.
  - FD를 지정해 `stdout(1)`, `stderr(2)`, 파일 등 대상이 유연합니다.
- 이후 `ft_printf`를 구현하며 버퍼링은 사용하지 않더라도 포맷 파싱과 가변인자(`va_list`) 처리 능력을 학습합니다.

## 재사용 관계와 학습 흐름
- `libft` → 모든 프로젝트의 기반 유틸 (문자열/메모리/리스트/출력)
- `get_next_line` → `so_long`의 맵 파싱 등 입출력에 재사용
- `ft_printf` → `libft`에 의존하며 출력을 풍부하게 (형식/가변인자)
- `push_swap` → `libft` 재사용 + 알고리즘/자료구조 연습
- `so_long` → `libft`/`get_next_line` 재사용 + `mlx`로 그래픽 처리
- `minitalk` → `libft` 재사용 + 시그널 기반 간단 IPC 구현

## 폴더 개요
- `libft`: 가장 기초적인 C 유틸을 라이브러리로 구성
- `get_next_line`: 파일 디스크립터로부터 줄 단위 읽기 구현
- `ft_printf`: `printf`의 제한된 포맷셋 구현과 가변인자 처리
- `push_swap`: 제한된 연산으로 스택 정렬, 알고리즘 훈련
- `so_long`: 맵 파싱과 그래픽 렌더링, 이벤트 처리
- `minitalk`: 시그널로 서버/클라이언트 통신

각 프로젝트별 자세한 내용은 하위 README를 참고하세요.