# ft_printf

C의 `printf`를 제한된 포맷셋으로 직접 구현합니다. 가변인자(`va_list`)의 개념과 사용법을 이해하고, 포맷 파싱과 정수/포인터 출력 로직을 작성합니다.

## 빌드
```bash
make
```
- `libftprintf.a` 생성
- 내부적으로 `libft`를 `bonus`로 빌드해 확장 함수 사용

## 지원 포맷
- 문자/문자열/포인터/정수: `%c`, `%s`, `%p`, `%d/%i`, `%u`, `%x/%X`
- 상수:
  - `DIGITS` = `"0123456789abcdef0123456789ABCDEF"`
  - 타입 집합: `ALLTYPES`, `HEXA`, `CAPITAL`, `SIGNED`

## 동작 개요
- 메인 루프: `ft_printf`가 포맷 문자열을 순회하며 `%` 처리
- 가변인자:
  - `va_start(ap, format)` → `va_arg`로 인자 추출 → `va_end(ap)`
- 출력 카운트:
  - 각 출력은 `ft_putchr_cnt`로 실제 바이트 수를 합산
- 숫자 출력:
  - `init_struct`로 진법/대소문자 설정
  - `putnbr_int`, `putnbr_long`는 재귀로 자리수 출력

예시:
```c
int cnt = ft_printf("n=%d hex=%x str=%s\n", 42, 0x2a, "hello");
```

## write와의 관계
- `ft_printf` 이전에는 포맷팅 없이 `write`로 정확한 바이트 출력만 수행했습니다.
- `ft_printf`에서는 포맷 파싱, 진법 변환, 가변인자 처리 등 고수준 기능을 직접 구현해 `write` 기반 출력에 로직을 더합니다.

## 한계/확장 아이디어
- 폭/정밀도(`%5d`, `%.3f` 등) 미구현
- 부동소수점 미지원
- 버퍼링 최적화 여지(현재 재귀/단건 write)