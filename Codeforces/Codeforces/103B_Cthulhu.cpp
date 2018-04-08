#include <iostream>
#include <vector>

using namespace std;

int n, m;
int visit[101];
vector<vector<int>> graph(101);
int cycle;
void dfs(int node, int parent)
{
	visit[node] = 1;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (graph[node][i] != parent && visit[graph[node][i]] == 1)//방문할 노드 중 부모 노드가 아니면서 이미 방문한 노드가 있다
		{//즉 사이클이 존재한다., 사이클을 체크할 때 두 노드가 서로 덧셈이 되어 2씩 증가한다.
			cycle++;
		}
		
		if (visit[graph[node][i]] == 0)
		{
			dfs(graph[node][i], node);
		}
	}
	return;
}

int main()
{
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int count = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i, i);
			count++;//연결되지 않은 그래프가 존재하는 경우 체크.
		}
	}
	
	cycle /= 2;//사이클이 하나 체크될 때마다 2개씩 올라가기떄문.
	
	if (cycle==1 && count==1)
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;
	//system("pause");
	return 0;
}