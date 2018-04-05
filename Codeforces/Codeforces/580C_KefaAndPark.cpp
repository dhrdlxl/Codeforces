#include <iostream>
#include <vector>//using vector(graph)
using namespace std;

int n;//verticies
int m;//maximum number of consecutive verticies with cats
int mask[100001];
int visited[100001];//check if we visit the vertex
vector<vector<int>> graph;
int answer = 0;


void dfs(int visit, int counter )
{
	if (mask[visit] == 1) counter++;//cat
	else counter = 0;//no cat

	visited[visit] = 1;//visit.

	if (counter > m) return;//fail
	else
	{
		
		bool isleaf = true;
		for (int i = 0; i < graph[visit].size(); i++)
		{
			if (visited[graph[visit][i]] == 0)
			{
				dfs(graph[visit][i], counter);
				isleaf = false;
			}
		}
		if (isleaf == true)
		{
			answer++;
		}
	}
}


int main()
{
	cin >> n>> m;
	for (int i = 1; i < n + 1; i++)//get where are the cats
	{
		scanf_s("%d", &mask[i]);
	}

	graph =  vector<vector<int>>(n+1);

	int x, y;
	for (int i = 0; i < n-1; i++)//construct graph
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);//Undirected graph
	}

	dfs(1,0);//1 is root

	cout << answer;

	//system("pause");
	return 0;
}