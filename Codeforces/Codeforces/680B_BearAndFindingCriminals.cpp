#include <iostream>
#include <algorithm>//using min, max

using namespace std;

int n;//number of cities
int a;//index of city where the police lives
int t[101];
int main()
{
	cin >> n >> a;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &t[i + 1]);//1~
	}
	int count = 0;
	count += t[a];//Criminal in a_th city

	int j = min(a - 1, n - a);
	for (int i = 1; i <= max(a - 1, n - a); i++)
	{
		if (i <= j)
		{
			if (t[a - i] * t[a + i]) count += 2;// 0 or 1
		}
		else
		{
			if (a <= n / 2)
			{
				count += t[a + i];
			}
			else count += t[a - i];
		}
	}

	cout << count;
	//system("pause");
	return 0;
}