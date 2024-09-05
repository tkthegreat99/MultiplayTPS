# MultiplayTPS
---
> 개발 기간 : 2024.07~2024.09
---
### 프로젝트 소개

C++ 프로젝트로 만든 TPS 멀티플레이 게임.

#### 게임 진행 방식
서버 실행 후 플레이어의 접속 대기적절한 인원 수가 채워진다면 카운트 다운 후 게임 시작
최후의 1인이 나올 때까지 전투. 최후의 1인이 나오면 최종 우승자가 된다.

#### 주요 기능

- Animation Layer Interface 를 사용하여 플레이어의 무기 장착 여부에 따라 쉽게 애니메이션 변경.
- RPC_server, Owningclient, Netmulticast를 활용한 멀티플레이 게임 진행
- Replicated, ReplicatedUsing을 통한 서버와 클라, 클라이언트간 동기화
- Lobby, title, Loading Level에 따른 각각의 GameMode, PlayerController
- Dedicated Server 환경을 가정한 멀티플레이

