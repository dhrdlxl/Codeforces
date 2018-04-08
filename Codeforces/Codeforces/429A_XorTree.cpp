#include <iostream>
#include <vector>

using namespace std;

int n;
int visit[100001];//�ش� ��带 �湮�ߴ��� üũ.
int mask1[100001];//init ��
int mask2[100001];//goal
int check[100001];//0 ���� / 1 Ȧ�� / 2 ¦�� / 3 �Ѵ�
vector<int> answer;
vector<vector<int>> tree;

void dfs(int node, int depth)//dfs�� �׷��� Ž��.
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
	
	if (mask1[node] ^ mask2[node])//���� �ٸ� ��(exclusive or)
	{
		mask1[node] = mask2[node];//flip
		answer.push_back(node);//���信 �߰�.
		if (depth % 2)//depth Ȧ��
		{
			if (check[node] == 1 || check[node] == 3)//Ȧ���϶� �̹� flip�� �ؾ��ϴ� ���
			{
				check[node]--;
			}
			else//Ȧ���϶� �ƹ��͵� ���ϴ� ���
			{
				check[node]++;
			}
		}
		else {//¦��
			if (check[node] == 2 || check[node] == 3)//¦���϶� �̹� flip�ϰ�������
			{
				check[node] %= 2;
			}
			else {
				check[node] += 2;
			}
		}
	}

	//leaf�϶�, �ƴ� ��(dfs)
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
		tree[v].push_back(u);//���� �׷����� �����Ѵ�.(visit�� ���� treeó�� ����Ѵ�.)
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