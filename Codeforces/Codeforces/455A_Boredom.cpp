#include <iostream>

using namespace std;

int n;
__int64 a[100003];

int main()
{
	cin >> n;
	int x;
	__int64 max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
		if (x > max)
			max = x;
	}

	__int64 answer = 0;
	
	for (__int64 i = 1; i <= max; i++)
	{
		if (a[i] != 0)
		{
			if (a[i + 1] == 0)
			{
				answer += a[i] * i;
			}
			else//�ڿ� ���ӵǴ� ���ڵ���  ���� ��.
			{
				int k = 1;//���ӵǴ� ���� ���۵Ǵ� �κ�.
				while (1)
				{
					a[i] = a[i] * i;
					if (k == 3)
					{
						a[i] = a[i - 2] + a[i];
					}
					else if (k > 3)
					{
						if (a[i - 2] >= a[i - 3])
						{
							a[i] = a[i - 2] + a[i];
						}
						else
						{
							a[i] = a[i - 3] + a[i];
						}
					}

					if (a[i + 1] == 0 || i==max) break;//�ڿ� ���̻� ���ڰ� ���ӵ��� �ʰų� ������ �����϶�.
					i++;
					k++;
				}
				if (a[i] >= a[i - 1])
					answer += a[i];
				else answer += a[i - 1];
			}
		}
		
	}
	cout << answer << endl;
	//system("pause");
	return 0;
}