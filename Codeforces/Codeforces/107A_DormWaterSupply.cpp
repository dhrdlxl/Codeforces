#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int,int>>> g;
int check[1001];//들어오는 엣지가 있는지 판단.
vector<int> answer;
int n, p;
int counter;
void dfs(int root, int now, int min)
{
	if (g[now].size() == 1)//다음 노드가 있다면.
	{
		if (g[now][0].second < min)
			min = g[now][0].second;
		dfs(root, g[now][0].first, min);
	}
	else if (g[now].size() == 0)//다음 노드가 없다 즉 leaf.
	{
		if (root == now)
		{
			return;
		}
			
		answer.push_back(root);
		answer.push_back(now);
		answer.push_back(min);
		counter++;
		return;
	}
	
}

int main()
{
	cin >> n >> p;
	g = vector<vector<pair<int, int>>>(n + 1);

	int x, y, z;
	
	for (int i = 0; i < p; i++)
	{
		cin >> x >> y >> z;
		g[x].push_back(make_pair(y, z));
		check[y]++;//들어오는 엣지가 있으면 증가.
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 0)//들어오는 엣지가 없을 때만.
		{//(들어오는게 있으면 그래프의 중간이거나, 연결된 그래프다.)
			dfs(i,i,1000001);//첫 루트노드, 현재 보고 있는 노드, 파이프의 최솟값
		}
		
	}

	cout << counter << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << answer[i*3] << " " << answer[i*3 + 1] << " " << answer[i*3 + 2] << endl;
	}
	//system("pause");
	return 0;
}