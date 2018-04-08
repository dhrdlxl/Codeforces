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
		if (graph[node][i] != parent && visit[graph[node][i]] == 1)//�湮�� ��� �� �θ� ��尡 �ƴϸ鼭 �̹� �湮�� ��尡 �ִ�
		{//�� ����Ŭ�� �����Ѵ�., ����Ŭ�� üũ�� �� �� ��尡 ���� ������ �Ǿ� 2�� �����Ѵ�.
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
			count++;//������� ���� �׷����� �����ϴ� ��� üũ.
		}
	}
	
	cycle /= 2;//����Ŭ�� �ϳ� üũ�� ������ 2���� �ö󰡱⋚��.
	
	if (cycle==1 && count==1)
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;
	//system("pause");
	return 0;
}