#include <iostream>
#include <algorithm>//using sort
using namespace std;

int n;
//int t[1000000001];

int main()
{
	cin >> n;
	int* t = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &t[i]);
	}

	sort(t, t + n);//Sorting in Ascending order
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum <= t[i]) {
			count++;
			sum += t[i];
		}
	}
	cout << count;
	delete[] t;
	//system("pause");
	return 0;
}