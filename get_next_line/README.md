# get_next_line

파일 디스크립터(FD)로부터 줄 단위로 데이터를 읽어오는 함수를 구현합니다. 운영체제의 파일 시스템, 커널, 시스템 콜, FD, 그리고 C의 `static` 변수 활용까지 학습합니다.

## 핵심 개념
- 파일 시스템과 커널: 유닉스/리눅스에서 파일은 FD로 식별되며 `read` 시스템 콜을 통해 커널 버퍼에서 사용자 공간으로 데이터를 복사합니다.
- 시스템 콜: `read(fd, buf, size)`는 커널에 요청을 보내 실제 I/O를 수행합니다.
- FD 관리: 여러 FD를 동시에 처리하기 위해 `static char *backup[OPEN_MAX + 1]`와 같은 구조를 사용합니다.
- 버퍼링: `BUFFER_SIZE`만큼씩 읽어 내부 버퍼에 축적하고, 개행을 기준으로 분리합니다.

## 구현 스케치
- 버퍼 축적: `append_buf(s_save, buf)`로 저장 문자열에 새 버퍼를 붙입니다.
- 탐색/분리: `ft_strchr(*backup, '\n')` 탐지 후 분리, 없으면 반복 읽기
- `push_swap/get_next_line.c` 예:
  - `backup[fd]`를 FD별로 유지
  - `read_file` → `separate_line` 흐름으로 한 줄 반환
- 메모리 관리: 새로 할당 후 이전 포인터 해제, 실패 시 `NULL` 반환

## 공통 인터페이스
```c
char *get_next_line(int fd);
```

## 사용 예
```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)))
{
    // 라인 처리
    free(line);
}
close(fd);
```

## 에지 케이스
- EOF 직후 마지막 라인 반환
- `read`가 `-1`인 오류 처리
- 큰 파일/작은 `BUFFER_SIZE`에서의 성능 고려

## 심화 정리 자료
- 유닉스 FD/파이프/소켓의 공통성
- 커널 버퍼와 사용자 공간 복사
- `static` 변수의 수명/스레드 안전 주의