#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int,int>>> g;
int check[1001];//������ ������ �ִ��� �Ǵ�.
vector<int> answer;
int n, p;
int counter;
void dfs(int root, int now, int min)
{
	if (g[now].size() == 1)//���� ��尡 �ִٸ�.
	{
		if (g[now][0].second < min)
			min = g[now][0].second;
		dfs(root, g[now][0].first, min);
	}
	else if (g[now].size() == 0)//���� ��尡 ���� �� leaf.
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
		check[y]++;//������ ������ ������ ����.
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 0)//������ ������ ���� ����.
		{//(�����°� ������ �׷����� �߰��̰ų�, ����� �׷�����.)
			dfs(i,i,1000001);//ù ��Ʈ���, ���� ���� �ִ� ���, �������� �ּڰ�
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