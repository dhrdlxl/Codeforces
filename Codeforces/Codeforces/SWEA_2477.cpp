#include <iostream>
#include <vector>//vector
#include <utility>//make_pair, pair
#include <queue>
using namespace std;

int main()
{
	int T;//
	cin >> T;
	for (int x = 1; x < T+1; x++)
	{
		int N, M, K, A, B;
		cin >> N >> M >> K >> A >> B;
		int a_tick[10] = { 0, };//첫 번째 창구 이용시간 저장할 배열
		int b_tick[10] = { 0, };//두 번째 창구 이용시간 저장할 배열
		int t[1001] = { 0, };//고객 도착시간 저장할 배열
		for (int i = 1; i < N + 1; i++)//첫 번째 창구 이용시간
		{
			scanf_s("%d", &a_tick[i]);
		}
		for (int i = 1; i < M + 1; i++)//두 번째 창구 이용시간
		{
			scanf_s("%d", &b_tick[i]);
		}
		for (int i = 1; i < K + 1; i++)
		{
			scanf_s("%d", &t[i]);
		}
		//여기까지 입력받는다.

		queue<int> que1;//첫 번째 창구 대기열
		queue<int> que2;//두 번째 창구 대기열

		vector<vector<pair<int, int>>> a(N + 1);//첫 번째 창구 현재 상태
		//a = vector<vector<pair<int, int>>>(N + 1);
		vector<vector<pair<int, int>>> b(M + 1);//두 번째 창구 현재 상태



		int tick = 0;//시간의 흐름.
		int j = 1;//첫번째 창구 대기열에 들어갈 때 쓸 변수

		int answer[1001] = {0,};//고객이 해당 창구를 이용하면 +1 할 배열
		int counter = 0;

		//실제 시뮬레이션 부분.
		while (counter < K) {
			for (; t[j] == tick;) {//고객이 도착했을때 큐에 넣음.
				que1.push(j);
				j++;
			}

			for (int i = 1; i < N + 1; i++)//첫번째 창구 탐색
			{
				if (a[i].size() == 1)//현재 처리중인 창구이면
				{
					if (tick - a[i][0].second == a_tick[i])//현재시간 - 고객이 들어온 시간 == 창구 처리시간
					{//즉 처리 완료했을 때
						que2.push(a[i][0].first);//두 번째 창구 대기열에 넣음
						a[i].pop_back();//첫번째 해당 창구의 고객 제거
					}
				}
				if (a[i].size() == 0)//창구에 고객이 없을 때.
				{
					if (que1.size() > 0)//기다리는 사용자가 있으면
					{
						a[i].push_back(make_pair(que1.front(), tick));//가장 먼저 온 고객, 현재 시간을 넘긴다.
						if (i == A)//분실 고객과 같은 창구이면
						{
							answer[que1.front()]++;//해당 손님의 값 1증가.(2가 되면 정답으로 더해진다.)
						}
						que1.pop();//고객이 창구에 갔으므로 대기열에서 제거
					}
				}
			}

			//두 번째 창구에서 나갈때 counter++ 해주자.
			for (int i = 1; i < M + 1; i++)//두번 째 창구 탐색.
			{
				if (b[i].size() == 1)//현재 처리중인 창구이면
				{
					if (tick - b[i][0].second == b_tick[i])//현재시간 - 고객이 들어온 시간 == 창구 처리시간
					{//즉 처리 완료했을 때
						b[i].pop_back();//두번째 해당 창구의 고객 제거
						counter++;//고객이 다 나가면 끝나도록.
					}
				}
				if (b[i].size() == 0)//창구에 고객이 없을 때.
				{
					if (que2.size() > 0)//두번째 창구를 기다리는 사용자가 있으면
					{
						b[i].push_back(make_pair(que2.front(), tick));//가장 먼저 온 고객, 현재 시간을 넘긴다.
						if (i == B)//분실 고객과 같은 창구이면
						{
							answer[que2.front()]++;//해당 손님의 값 1증가.(2가 되면 정답으로 더해진다.)
						}
						que2.pop();//고객이 창구에 갔으므로 대기열에서 제거
					}
				}
			}
			//시간 증가
			tick++;
		}
		
		int sum = 0;
		for (int i = 1; i < 1001; i++)
		{
			if (answer[i] == 2) sum += i;
		}
		if (sum == 0)
			sum = -1;
		
		cout << "#" << x << " " << sum<<endl;
	}
	

	system("pause");
	return 0;
}