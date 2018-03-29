#include <iostream>

using namespace std;

int n;
__int64 a;
int x[10];
int main()
{
	cin >> n >> a;

	for (int i = 0; i < n; i++)
	{
		switch (a % 10)
		{
		case 2:
			x[2]++;
			break;
		case 3:
			x[3]++;
			break;
		case 4:
			x[2] += 2;
			x[3]++;
			break;
		case 5:
			x[5]++;
			break;
		case 6:
			x[5]++;
			x[3]++;
			break;
		case 7:
			x[7]++;
			break;
		case 8:
			x[7]++;
			x[2] += 3;
			break;
		case 9:
			x[7]++;
			x[3] += 2;
			x[2] += 1;
			break;
		default:
			break;
		}
		a /= 10;
	}

	for (int i = 9; i >0; i--)
	{
		for (int j = 0; j < x[i]; j++)
			cout << i;
	}

	//system("pause");
	return 0;
}