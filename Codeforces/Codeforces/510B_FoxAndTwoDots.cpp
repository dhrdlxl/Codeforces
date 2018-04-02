#include <iostream>
#include <stack>//stack
#include <utility>//pair, make_pair
using namespace std;

int n;
int m;
char dot[51][51];
int mask[51][51];

stack<pair<int, int>> st;

int main()
{
	cin >> n >> m;

	char ch;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch;
			dot[i][j] = ch;
		}
	}

	int x = 0;
	int y = 0;
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (mask[i][j] == 0)// 0 means didn't visit
			{
				st.push(make_pair(i, j));
				while (!st.empty())
				{
					x = st.top().first;
					y = st.top().second;
					mask[x][y] = 1;//visit
					st.pop();// stack pop
					

					if (dot[x + 1][y] == dot[i][j])//down
					{
						
						if (mask[x + 1][y] == 0)//didn't visited
						{
							st.push(make_pair(x + 1, y));//stack push
						}
						else
							count++;
					}


					if (dot[x][y + 1] == dot[i][j])//right
					{
						if (mask[x][y + 1] == 0)//if didn't visit
						{
							st.push(make_pair(x, y + 1));//stack push
						}
						else
							count++;
					}
					if (x - 1 >= 0)
					{
						if (dot[x - 1][y] == dot[i][j])//up
						{
							if (mask[x-1][y] == 0)//didn't visited
							{
								st.push(make_pair(x - 1, y));//stack push
							}
							else count++;
						}
					}
					if (y - 1 >= 0)
					{
						if (dot[x][y-1] == dot[i][j])//left
						{
							if (mask[x][y-1] == 0)//didn't visited
							{
								st.push(make_pair(x, y-1));//stack push
							}
							else count++;
						}
					}
					if (count > 1)
					{
						cout << "Yes" << endl;
						return 0;
					}
					count = 0;
				}
			}
		}
	}
	cout << "No" << endl;
	//system("pause");
	return 0;

}