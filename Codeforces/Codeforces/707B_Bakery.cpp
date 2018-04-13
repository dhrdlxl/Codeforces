#include<iostream>

using namespace std;
int n, m, k;
int info[100001][3];
int mask[100001];
int main()
{
	cin >> n >> m >> k;

	
	int x, y, z;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		info[i][0] = x;
		info[i][1] = y;
		info[i][2] = z;
	}
	int k_value;
	for (int i = 0; i < k; i++)
	{
		cin >> k_value;
		mask[k_value] = 1;
	}
	int min = 1000000001;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (mask[info[i][0]]^mask[info[i][1]])//µÑÁß ÇÏ³ª¸¸ ¼³ÅÁÀ» ÆÈ¶§.
		{
			if (info[i][2] < min)
			{
				min = info[i][2];
				count++;
			}
		}
	}
	if (count == 0)cout << -1 << endl;
	else cout << min << endl;
	//system("pause");
	return 0;
}