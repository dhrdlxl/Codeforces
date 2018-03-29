#include <iostream>
#include <queue>
using namespace std;

int n;//number of books
int t;//number of free minutes
queue<int> a;
int main()
{
	cin >> n >> t;
	int sum = 0;
	int max_count = 0;//maximum number of books
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		
		while ((sum + x > t) && (!a.empty()))
		{
			sum -= a.front();
			a.pop();
		}
		if (x > t)
		{
			sum = 0;
			continue;
		}
		a.push(x);
		sum += x;
		if (a.size() > max_count) max_count = a.size();

	}

	cout << max_count;
	//system("pause");
	return 0;
}