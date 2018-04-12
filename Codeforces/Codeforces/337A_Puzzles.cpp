#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int f[51];
int main()
{
	cin >> n >> m;
	int _f;
	for (int i = 0; i < m; i++)
	{
		cin >> _f;
		f[i] = _f;
	}

	sort(f, f + m);
	int min = 1000;
	for (int i = 0; i <= m - n; i++)
	{
		if (f[i + n-1] - f[i] < min)
			min = f[i + n-1] - f[i];
	}

	cout << min << endl;
	//system("pause");
	return 0;
}