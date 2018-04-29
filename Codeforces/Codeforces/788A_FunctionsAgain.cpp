#include <iostream>
#include <algorithm>

using namespace std;

int n;
__int64 differ[100003];
__int64 dp[100003];

int main()
{
	cin >> n;
	int pre;
	cin >> pre;
	int now;

	
	for (int i = 0; i < n-1; i++)
	{
		cin >> now;
		differ[i] = abs(now - pre);
		pre = now;
	}
	if (n == 2) {
		cout << differ[0] << endl;
		return 0;
	}
		
	dp[0] = differ[0];
	dp[1] = differ[1];
	__int64 maximum = max(dp[0], dp[1]);
	for (int i = 2; i < n - 1; i++)
	{
		dp[i] = max(differ[i], dp[i - 2] - differ[i - 1] + differ[i]);
		if (maximum < dp[i])
			maximum = dp[i];
	}

	//int answer = max(dp[n - 2], dp[n - 3]);
	//if (maximum > answer) answer = maximum;
	cout << maximum << endl;
	//system("pause");
	return 0;
}