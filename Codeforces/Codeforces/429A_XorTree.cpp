#include <iostream>
#include <vector>

using namespace std;

int n;
int visit[100001];//해당 노드를 방문했는지 체크.
int mask1[100001];//init 값
int mask2[100001];//goal
int check[100001];//0 없음 / 1 홀수 / 2 짝수 / 3 둘다
vector<int> answer;
vector<vector<int>> tree;

void dfs(int node, int depth)//dfs로 그래프 탐색.
{
	visit[node] = 1;
	switch (check[node])
	{
	case 1:
		if (depth % 2 == 1)
			mask1[node] = !mask1[node];
		break;
	case 2:
		if (depth % 2 == 0)
			mask1[node] = !mask1[node];
		break;
	case 3:
		mask1[node] = !mask1[node];
		break;
	}
	
	if (mask1[node] ^ mask2[node])//값이 다를 때(exclusive or)
	{
		mask1[node] = mask2[node];//flip
		answer.push_back(node);//정답에 추가.
		if (depth % 2)//depth 홀수
		{
			if (check[node] == 1 || check[node] == 3)//홀수일때 이미 flip을 해야하는 경우
			{
				check[node]--;
			}
			else//홀수일때 아무것도 안하는 경우
			{
				check[node]++;
			}
		}
		else {//짝수
			if (check[node] == 2 || check[node] == 3)//짝수일때 이미 flip하고있으면
			{
				check[node] %= 2;
			}
			else {
				check[node] += 2;
			}
		}
	}

	//leaf일때, 아닐 때(dfs)
	for (int i = 0; i < tree[node].size(); i++)
	{
		if (visit[tree[node][i]] == 0)
		{
			check[tree[node][i]] = check[node];
			dfs(tree[node][i], depth + 1);
		}
	}
	
	return;
}

int main()
{
	cin >> n;
	tree = vector<vector<int>>(n+1);
	
	int u, v;
	for (int i = 0; i < n-1; i++)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);//무향 그래프를 생성한다.(visit을 통해 tree처럼 사용한다.)
	}

	for (int i = 1; i < n+1; i++)//init mask
	{
		scanf_s("%d", &mask1[i]);
	}
	for (int i = 1; i < n + 1; i++)//goal mask
	{
		scanf_s("%d", &mask2[i]);
	}

	dfs(1, 1);
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
	//system("pause");
	return 0;
}