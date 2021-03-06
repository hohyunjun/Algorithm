# 삼성 SW역량테스트 준비 - 연습

 ## Brute Force
  - 모든 경우의 수를 다 만들어 보는 알고리즘
  - 이 때, 모든 경우의 수를 어떻게 만들 것인가?
   + For 문
   + 순열
   + 재귀함수
   + 비트마스크
  - 리모컨(BOJ 1107)
   + 못풀었다;; 브루트 포스 왜이렇게 어렵지
   + +나 -를 누르다가 숫자 버튼을 누르는 순간 그 전까지 입력한 것이 모두 의미 없어진다.
   + 이 문제는 버튼을 누르는 최솟값을 구하는 것이므로 의미 없는 것이 있는 방법은 절대 최솟값이 될 수 없다.
   + 마찬가지로 5,4,5,5,-,-,+,+,+,+ 같은 경우는 절대 답이 될 수 없다. 
   + 같은 값을 두 번 이상 방문하는 경우(중복이 있는 경우)는 절대 최소가 될 수 없다. 
   + 최솟값을 구하는 문제의 두 가지 원칙 : 의미 없는 연산은 하지 않는다. 중복되는 것을 하지 않는다. 
   + 즉 이 문제에서 반드시 숫자 버튼을 먼저 누른 후에 +/- 버튼을 어떻게 누를지 결정해 주어야 한다. 
   + 또한, -/+ 를 섞어서 누를 수 없다. +/- 중에서 어떤 것을 누를지 결정한 후 그것만 눌러야 한다. 
   + 우리가 이동하는 채널 C는 500,000을 넘을 수 있다. (채널은 무한대이다)
   + +나 -를 누르는 횟수 계산은 뺄셈으로 구할 수 있다.
   + 문제풀이 전략
    - 이동할 채널 C를 정한다( 0 <= C <= 1000000 )
    - C에 포함되어 있는 숫자 중에 고장난 버튼이 있는지 확인한다.
    - 고장난 버튼이 포함되어 있지 않다면 |C-N|을 계산해 + 나 - 버튼을 몇 번 눌러야 하는지를 계산한다. 
   + 위 방법이 고장난 버튼이 있는지를 확인해 이동할 채널을 선택하는 것보다 훨씬 간편하다.
   + 브루트 포스 문제 치고는 꽤 복잡한 축에 속하는 문제이다. 까다로운 문제
  - 건너 뛰며 해보기 : 모든 경우를 해보는 것은 아니고, 나올 수 없는 특정한 경우는 제외하고 검사를 진행하는 것
  - 카잉 달력(BOJ 6064)
   + 시간초과????
   + 하루종일 잡고있었던 문제.. 짜증나서 그냥 구글링해서 코드보고 풀었다.
   + 1 <= M,N <= 40,000
   + 전체 경우의 수는 MN = 1,600,000,000 가지라서 너무 많다.
   + x값을 고정해 놓고 y값만 비교한다.
  - **순열 사용하기 문제**
  - 부등호(BOJ 2529)
   + 얘도 못풀었음;; 순열 이용해서 풀었는데 시간초과뜸
   + 순열을 사용하기 전에 어떤 수를 먼저 사용할지를 결정하고 그 다음에 순열을 사용해야 한다.
   + 여기서 이 문제의 가장 큰 문제점이 나온다. 바로, 순열을 한 번만 사용하는 것이 아니라는 것
   + 10개 중에 k+1개의 숫자를 뽑고, 그 숫자로 또 순열을 돌려야 하는데, --> 이렇게 풀어서 시간초과떴다
   + *최대값과 최소값*이라는 조건을 이용해서 시간 내에 풀 수 있다.
   + 예를 들어, k+1이 3일 경우 최대값은 9,8,7로만 이루어져 있을 것이고, 최소값은 0,1,2로만 이루어져 있을 것이다.
   + 순열 2번 돌리면 되는데, 최대, 최소를 비교하는 것과 결과값을 출력하는 과정의 예외처리에 주의해야 한다.
  - 단어 수학(BOJ 1339)
   + 이것도 순열을 사용해서 나름 잘 풀었다고 생각했는데 시간초과가 뜬다;;
   + 서로 다른 알파벳이 10개 밖에 없고, 0~9까지의 수를 알파벳 하나로 나타냈다 -> 이 문제는 순열로 풀 수 있다
   + 순열로 푸는 과정은 맞았는데, 알파벳을 숫자로 변환하는 과정의 알고리즘에서 시간초과가 났다.
   + 원래의 알파벳 string을 숫자를 포함하는 string으로 바꾼 후 stoll 을 사용했는데,
   + 이렇게 하지 말고 알파벳 string에서 바로 숫자를 구하는 알고리즘으로 해야 시간 내에 풀 수 있다.
  - **백트래킹**
   + 재귀함수를 이용해서 브루트 포스 문제를 풀 때, 재귀함수는 이걸 호출해서는 절대 정답을 구할 수 없을 것 같은 경우에 함수호출을 진행하지 않고 종료시킨다.
   + 문제를 통해 어떤 경우에 함수 호출을 중단시켜야 하는지와, 어떤 형태의 알고리즘인지를 살펴본다. 
   + 백트래킹은 문제에 따라 탐색 종료를 결정할지 말지가 달라지므로, 문제를 꼼꼼히 읽어야 한다. 
  - 스타트와 링크(BOJ 14889)
   + 순열을 이용해서 풀었던 문제이다. 재귀함수를 이용한 백트래킹으로도 풀어보자.
   + 각각의 사람은 1번팀 혹은 2번팀에 속해야 한다. 
   + go(index, first, second)
    - index번째 사람을 어떤 팀에 넣을지 결정해야 함
    - 1번 팀과 2번 팀에 속한 사람이 각각 first, second에 들어가 있음.
    - 정답을 찾은 경우(모든 사람을 두 팀 중 한팀에 할당했을 경우) : index == n
     + 각 팀으로의 할당이 끝났으므로 능력치 차이를 구한다. 
    - 다음 경우
     + 1번팀에 들어간다 : go(index + 1, first, second)
     + 2번팀에 들어간다 : go(index + 1, first, second)
     + 재귀함수를 사용할 때, 함수 호출 전에 어떤 값에 변화를 줬다면 함수 호출이 끝나면 원래 상태로 다시 복원시켜 주어야 한다. 
    - 불가능한 조건(불필요한 조건)
     + first 또는 second의 크기가 n/2보다 커지는 경우는 해볼 필요가 없다.
     + 이렇게 불필요한 조건을 넣어주면 백트래킹 알고리즘의 속도가 빨라지게 된다.
  - 백트래킹 알고리즘의 경우, 일단 재귀함수를 이용해서 문제를 푼 다음,
  - 이렇게 호출되면 절대로 정답을 못 구할 것 같은 경우를 확인해서 찾아내야 한다. 
  - 이런 것들을 찾는 통찰력이 필요한데, 이는 문제를 풀면서 찾아나가야 한다.
  - 부등호(BOJ 2529)
   + 마찬가지로 순열을 이용해서 풀었던 문제이다. 백트래킹으로도 풀어본다.
   + 하.. 백트래킹으로 못풀었다;; 생각하기 너무 어려운 것 같다.
   + 재귀함수의 argument를 바꾸는 경우가 아니라, 그 외부에서 재귀함수의 호출에 영향을 주는 변수에 영향을 주었을 경우에는
     재귀함수 호출 후에 다시 원래 값으로 돌려야 한다. 
   + 백트래킹으로 다시 한 번 풀어봐야 할 문제!!
  - 백트래킹은 어떤 경우에 호출을 더 하면 안될지를 생각해보는 능력이 필요하다.
  - 맞춰봐(BOJ 1248)
   + 2529 문제와 비슷하게 백트래킹 알고리즘을 구현해 보았는데 틀렸다;
   + S[i][i] 가 A[i] 의 부호와 같다는 점을 이용해서 알고리즘을 구현해야 한다. 
  - N-Queen(BOJ 9663)
   + 백트래킹의 대표격인 문제.
   + 백트래킹 구현이 익숙하지 않아 못풀었다.
   + 코드 보면서 풀었던 문제. 나중에 꼭 다시 한 번 풀어볼 것.
  - 스도쿠(BOJ 2580)
   + 오.. 드디어 혼자 힘으로 풀어서 맞아봤다
   + exit(0) 함수는 프로그램 자체를 종료시키는 함수이다.
  - 알파벳(BOJ 1987)
   + 얘도 혼자 힘으로 풀었다!!!!!만세!!!
  - **비트마스크**
  - 스타트와 링크(BOJ 14889)
   + 비트마스크를 이용해서도 풀 수 있다.
   + 비트가 0인사람은 0번 팀, 1인 사람은 1번 팀이라고 하고 전체 경우의 수를 순회할 수 있다.
   + 비트마스크 문제를 풀 때는 항상 연산자 우선순위에 주의한다!
  - 종이 조각(BOJ 14391)
   + N,M 제한이 4로, 매우 작다
   + 하지만, 종이를 자르는 경우의 수를 어떻게 다 계산하지?;; 여기서 아이디어가 떠오르지 않았다. 
   + 숫자에 0이 없다면 4자리로만 자르는게 정답이 된다. 하지만, 0이 있다면 얘기가 달라진다. 
   + 결국, 모든 방법을 다 시도해 보아야 한다. 
   + 가로와 세로가 포인트이다!! 모든 칸은 가로 또는 세로 칸에 속하게 된다. 
   + 각각의 칸은 가로 또는 세로에 속해야 하는데 칸의 개수는 MN 개이다. 
   + 실제 경우의 수는 2^MN = 2^16 = 65536 가지
   + 각각의 칸에 대해서, 세로인지 가로인지를 정해주면 된다.(0과 1로 모델링)
  - 가르침(BOJ 1062)
   + 풀었는데 시간초과가 떴다 ㅠ
   + 시간초과 뜬거 해결했는데, 41%에서 계속 틀렸다ㅠㅠㅠㅠㅠ
   + 질문 검색해서 풀었다.; 
   + 생각했던 방식으로 계속 안 풀릴 때는 접근법을 다시 찾아볼 것.
  - 구슬 탈출2(BOJ 13460)
   + 전체 경우의 수는 4^10
   + 같은 방향으로의 연속된 이동은 탐색할 필요가 없다.
   + 따라서, 경우의 수는 4*3^9
   + 또한, 한 방향으로 이동한 다음, 반대 방향으로 바로 이동하는 것도 의미가 없다.
   + 따라서 경웅의 수는 4*2^9 = 2048 가지
   + 먼저, 이동 가능한 방법을 비트마스크를 이용해 4^10가지를 만든 다음 앞 페이지에 나온 두 가지 경우를 모두 제외
   + 4진법으로 변환해서 경우의 수를 모두 만든다. --> 어떻게?? 
   + 각각의 방향을 0,1,2,3으로 모델링
   + simulate 하는 과정이 매우 복잡하다 -> 함수로 잘게 쪼개서 만든다
   + 일단은 코드 보고 짜봤다. 나중에 다시 해보기!!
  - 2048Easy(BOJ 12100)
   + 구슬 탈출 문제와 비슷한 방식으로 풀 수 있다.
   + 전체 경우의 수는 4^5 이므로 0부터 2^10-1까지 값을 비트마스크로 만들어 4진수로 바꾼 뒤 방향을 설정한다.
   + 주의할 것은 방향에 따라 simulate 우선순위가 있다는 것이다. 확인!!

 ## Brute Force : 일부 경우만 해 보기
  - 모든 경우 다 해보기와 다르게 절대 정답이 될 수 없는 경우는 확인하지도 않을 수 있다.
  - 수들의 합2(BOJ 2003)

 ## Brute Force : 중간에서 만나기
  - 문제를 절반으로 나눠서 푸는 알고리즘
  - 양쪽 절반에서 모든 경우를 다 해보는 방법이다.
  - 탐색의 크기가 많이 줄어든다. 문제의 크기가 N인 경우에 2^N에서
  - 2^(N/2) + 2^(N/2)으로 줄어들게 된다.
  - Meet In the Middle(MITM) 이라고도 부른다. 
  - 부분집합의 합2(BOJ 1208)
   + 처음에 맞게 풀었었는데, 값의 크기가 int값의 범위를 넘어가는 경우로 인해 계속 틀렸다
   + 또한, 만들어진 vector의 범위를 넘어가는 경우도 체크해주지 않아 틀렸다.
   + 이런 것들에 주의해야 한다!!
  - 합이 0인 네 정수(BOJ 7453)
   + lower bound, upper bound 개념을 사용하면 쉽게 풀 수 있다.
   + 어떤 수 a의 lower bound는 a보다 크거나 같으면서 가장 작은 수이다.
   + 어떤 수 a의 upper bound는 a보다 크면서 가장 작은 수이다.
   + C++로 문제를 풀 때 사용해야 할 함수는 equal_range 함수이다. (적용하려는 배열은 정렬된 상태여야 한다.)
   ```c++
    for(int num:first){
        auto range = equal_range(second.begin(), second.end(), -num);
        ans += range.second-range.first;
    }
    // range.first 가 lower bound, range.second 가 upper bound이다.
   ```