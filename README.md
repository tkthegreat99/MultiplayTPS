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

![화면 캡처 2024-09-05 165834](https://github.com/user-attachments/assets/c140c0bb-88df-48c3-b926-5aee5ba32c7f)

서버와 두 개의 클라를 열고 테스트

![Honeycam 2024-09-05 16-59-26](https://github.com/user-attachments/assets/eb0f12be-6fa7-4b5f-a840-2bc5ad27dc01)

Lobby 레벨에서 Submit을 누르면 127.0.0.1/7777로 연결이 된다.

![Honeycam 2024-09-05 17-00-54](https://github.com/user-attachments/assets/6939ff58-bafa-4f48-9574-7d56ed9cd974)

입장 후 카운트 다운이 이루어지며, 이때는 무적상태

![Honeycam 2024-09-05 17-02-40](https://github.com/user-attachments/assets/ae75d8f0-00eb-4d7b-87b1-86578669a6ba)

클라 간 액터들과 애니메이션의 복제가 잘 이루어지는 것을 볼 수 있다.

![Honeycam 2024-09-05 17-03-05](https://github.com/user-attachments/assets/361f5711-77e3-4a61-a348-977b52dec99d)

상대가 죽으면, winnerUI가 뜨고 지면 LoserUI가 뜨면서 게임 종료.

