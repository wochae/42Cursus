# push_swap

두 개의 스택(`a`, `b`)과 제한된 연산으로 숫자를 정렬하는 알고리즘 연습 과제입니다. 자료구조 설계와 명령 최소화 전략을 학습합니다.

## 빌드
```bash
make
```
- `./push_swap` 생성 (`make bonus`가 있다면 `checker`도 생성)

## 자료구조
- 노드(`t_node`): `prev`/`next`/`num`/`index`
- 리스트(`t_list`): `top`/`bottom`/`size`
- 원형 이중 연결 리스트를 활용합니다.
  - `is_sorted`에서 `tmp->next == list->top` 검사로 원형 순회 완료를 판단

## 핵심 함수
- 초기화: `make_node`, `init_list`
- 상태: `is_sorted`, `get_top`, `ft_isnum`, `ft_numlen`
- 연산:
  - 스왑: `sa`, `sb`, `ss`
  - 푸시: `pa`, `pb`
  - 회전: `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- 정렬 전략:
  - 소규모: `sort_small`
  - 대규모: `sort_large` + 인덱싱/회전 판단(`is_rotate`)

## 입력/검증
- 숫자 판별: `ft_isnum`로 부호/숫자만 허용
- 범위/중복 체크는 `input.c` 흐름에서 수행 (libft의 `ft_atoi`/`ft_split` 보조)

## 사용 예
```bash
./push_swap 2 1 3 6 5 8
```
- 출력되는 명령열을 `checker`로 검증 가능합니다.

## 메모리 관리
- 종료: `free_t_list`, `free_t_lists`
- 오류: `error_exit`는 `stderr`에 "Error\n" 출력 후 `exit(1)`