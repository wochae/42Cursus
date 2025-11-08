# so_long

간단한 2D 맵을 파싱하고, `mlx` 라이브러리를 사용해 이미지를 렌더링하며, 키 이벤트로 플레이어를 움직이는 그래픽 과제입니다.

## 빌드
```bash
make
```
- `./so_long` 생성
- 의존성: `mlx` (macOS용 소스 포함), `libft`

## 구성
- 맵 파싱: `map_parse.c`, `map_check.c` (직사각형/벽 유효성, 구성 요소 검증)
- 렌더링: `map_print.c`, `operate.c`
- 리소스: `images/`에 `.xpm` 파일(플레이어/적/음식/벽/출구)
- 입력: `get_next_line`로 `.ber` 파일 읽기

## libft 활용
- 문자열/메모리 유틸: `ft_strlen`, `ft_split`, `ft_strjoin` 등
- 출력: `ft_putendl_fd` (문자열 유효성 검사 후 개행), 오류 메시지

## 실행 예
```bash
./so_long maps/map1.ber
```
- 맵을 로드하고 이미지를 그린 후, 키 입력으로 이동합니다.

## 렌더링/이벤트
- 초기 이미지 로드 → 타일 단위 그리기
- 키 이벤트로 플레이어 이동 → 수집/충돌/도착 처리
- 프레임 기반 갱신으로 실시간 화면 반영