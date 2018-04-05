#include <iostream>
#include <algorithm>//sort
using namespace std;

int n;//boy
int m;//girl
int a[101];
int b[101];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &b[i]);
	}

	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	int answer = 0;
	while (a[i]!=0 && b[j]!=0)
	{
		if (abs(a[i] - b[j]) <= 1)
		{
			answer++;
			i++;
			j++;
		}
		else {
			if (a[i] > b[j])j++;
			else i++;
		}
	}

	cout << answer;
	//system("pause");
	return 0;
}