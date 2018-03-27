//Using Fermat's theorem
#include <iostream>
#include<ctgmath>

using namespace std;

int n;//number

__int64 modular(int a1, int p_1, int p)
{
	__int64 a = a1;
	__int64 result = 1;
	while (p_1 > 0)
	{
		if (p_1 % 2 == 1)
		{
			result = (result*a) % p;
			p_1 = p_1 - 1;
		}
		p_1 = p_1 / 2;
		a = (a*a) % p;
	}
	return result;
}

int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		__int64 y;
		__int64 x;
		bool check = true;
		cin >> y;
		x = sqrt(y);

		if (x*x != y || y == 1)
			cout << "NO" << endl;
		else
		{
			int time = 11;
			for (int j = 2; j <= sqrt(x); j++)
			{
				int test = modular(j, x - 1, x);
				if (test != 1)
				{
					cout << "NO" << endl;
					check = false;
					break;
				}
				time--;
				if (time < 0)
					break;

			}
			if (check)
				cout << "YES" << endl;
		}
	}

	//system("pause");
	return 0;
}