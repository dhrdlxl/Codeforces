#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, k;
stack<int> a;
vector<int> b;
int main()
{
	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (i < n - k)//분배해야 하는 수
		{
			a.push(x);
		}
		else//고정된 수
		{
			b.push_back(x);
		}
	}
	if (n < k)//박스개수가 물품보다 많으면 물품개수만큼으로 해준다.
		k = n;

	int size = a.size();
	int max = b[k - 1];//가장 마지막이 제일 크므로.
	int num = 0;
	for (int i =0; i <size ; i++)
	{
		num = a.top();//스택에 있는 수 중 가장 큰 수
		a.pop();
		b[i] += num;
		if (max < b[i])max = b[i];
	}
	cout << max << endl;
	//system("pause");
	return 0;
}