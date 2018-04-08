#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tree(2001);
int max_depth;//트리의 최대 높이 
int pi[2001];

void dfs(int node, int depth)
{
	if (max_depth < depth)
	{
		max_depth = depth;
	}
	for (int i = 0; i<tree[node].size(); i++)
	{
		dfs(tree[node][i], 1 + depth);
	}
	return;
}

int main()
{
	cin >> n;

	int p;
	for (int i = 1; i<n + 1; i++)
	{
		cin >> p;
		pi[i] = p;
		if (p>0)
			tree[p].push_back(i);
	}

	for (int i = 1; i<n + 1; i++)
	{
		if (pi[i] == -1)//root노드.
		{
			dfs(i, 1);
		}
	}

	cout << max_depth << endl;
	return 0;
}