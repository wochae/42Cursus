# libft

C 표준 라이브러리의 핵심 기능을 재구현해 정적 라이브러리(`libft.a`)로 제공하는 프로젝트입니다. 이후 과제들에서 문자열, 메모리, 리스트, 간단 출력 함수 등을 공통으로 재사용합니다.

## 빌드
```bash
make
```
- `libft.a` 생성
- `clean`, `fclean`, `re`, `bonus` 지원 (프로젝트 변형에 따라 상이)

## 제공 범주
- 문자열: `ft_strlen`, `ft_strchr`, `ft_strlcpy`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_substr` 등
- 메모리: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- 문자: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- 변환/출력: `ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- 리스트(Singly): `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## 핵심 구현 포인트
- `ft_memmove`: 겹치는 메모리 영역을 안전하게 복사합니다.
  - 구현 예: 두 방향 처리(앞→뒤 또는 뒤→앞)로 오버랩 보호.
- `ft_putendl_fd`: 문자열 후 개행을 FD에 출력합니다.
  - `so_long/libft` 변형에서는 `s` 체크 후 길이 출력, `\n` 별도 출력.
- `ft_lstmap`: 새 리스트를 생성하며 변환 실패 시 `ft_lstclear`로 안전 해제.
- `ft_isprint`: 32~126 범위를 반환하는 간결한 구현도 존재합니다.

## 사용 예
```c
// 문자열 결합
char *path = ft_strjoin("maps/", "map1.ber");

// 안전 복사
ft_memmove(dst, src, len);

// 파일 디스크립터 출력
ft_putendl_fd("Error", 2);
```

## 재사용
- `ft_printf`에서 출력과 문자열 유틸 활용
- `push_swap`, `so_long`, `minitalk` 등 모든 프로젝트에서 의존