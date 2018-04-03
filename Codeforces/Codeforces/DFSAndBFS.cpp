#include <iostream>
#include <vector>//vector
#include <algorithm>//sort
#include <queue>//queue
using namespace std;

int n;
int m;
int v;
vector< vector<int> > graph;
queue<int> q;
int visited[1001];
int visited2[1001];

void dfs(int start)
{
	if (!visited[start])//visited[start]==0
	{
		visited[start] = 1;
		cout << start << " ";
		for (int i = 0; i < graph[start].size(); i++)
		{
			if (visited[graph[start][i]] == 0)
			{
				dfs(graph[start][i]);
			}
		}
	}
}

void bfs(int start)
{
	q.push(start);
	visited2[start] = 1;
	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		cout << next << " ";

		for (int i = 0; i < graph[next].size(); i++)
		{
			if (visited2[graph[next][i]] == 0)
			{
				q.push(graph[next][i]);
				visited2[graph[next][i]] = 1;
			}
			
		}
	}

}


int main()
{
	cin >> n >> m >> v;
	graph = vector< vector<int> >(n+1);//n(1~1000)

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);

	cout << endl;

	bfs(v);

	system("pause");
	return 0;
}