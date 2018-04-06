#include<iostream>

using namespace std;

int n;
int mask[101];
int xy[101][2];

void dfs(int point)
{
	for (int i = 0; i < n; i++)
	{
		if (mask[i] == 0)//didn't visit
		{
			if (xy[point][0] == xy[i][0] || xy[point][1] == xy[i][1])//same in X_Axis or Y_Axis
			{
				mask[i] = 1;//visit
				dfs(i);
			}
		}
	}
	return;//doesn't have same point
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)//get points' information
	{
		scanf_s("%d", &xy[i][0]);
		scanf_s("%d", &xy[i][1]);
	}

	int count = -1;//-1 because first root point must add 1 ==> count will become 0
	for (int i = 0; i < n; i++)
	{
		if (mask[i] == 0)//didn't visit yet
		{		
			mask[i] = 1;//visit.
			count++;//finding new root point.(it doesn't connect with other root points)
		}
		dfs(i);
	}

	cout << count<<endl;
	//system("pause");
	return 0;
}