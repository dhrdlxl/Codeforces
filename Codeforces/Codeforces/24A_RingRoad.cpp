#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
#include<cstring>
using namespace std;


int n;

vector<vector<pair<int,int>>> graph(101);
int mask[101];
int moving(int start,int move,int sum)
{
	if (mask[graph[move][0].first] == 0)
	{
		mask[graph[move][0].first] = 1;
		return moving(start, graph[move][0].first, sum + graph[move][0].second);
	}
	else if (mask[graph[move][1].first] == 0)
	{
		mask[graph[move][1].first] = 1;
		return moving(start, graph[move][1].first, sum + graph[move][1].second);
	}
	else
	{
		if (graph[move][0].first == start)
			sum += graph[move][0].second;
		else
			sum += graph[move][1].second;
		return sum;
	}
		
}

int main()
{
	cin >> n;//number of cities

	int a, b, c;
	int start_city;
	for (int i = 0; i < n; i++)//make directed graph
	{
		cin >> a >> b >> c;
		if (i == 0)start_city = a;
		graph[a].push_back(make_pair(b, 0));
		graph[b].push_back(make_pair(a, c));
	}
	int answer[2];
	for (int i = 0; i < 2; i++)
	{
		memset(mask, 0, sizeof(int) * 101);
		mask[start_city] = 1;
		mask[graph[start_city][i].first] = 1;
		answer[i] = moving(start_city, graph[start_city][i].first, graph[start_city][i].second);
	}
	
	cout << min(answer[0], answer[1]) << endl;

	//system("pause");
	return 0;
}