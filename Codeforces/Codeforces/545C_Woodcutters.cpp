#include <iostream>

using namespace std;

int n;//number of trees

int main()
{
	cin >> n;

	//n x 2 matrix
	int** data = new int*[n];
	for (int i = 0; i < n; i++)data[i] = new int[2];

	int x, h;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> h;
		data[i][0] = x;
		data[i][1] = h;
	}
	int count = 2;//start , end point
	if (n == 1)count = 1;
	int occupy = data[0][0];//first point


	for (int i = 1; i < n-1; i++)
	{
		if (data[i][0] - data[i][1] > occupy)//left
		{
			count++;
			occupy = data[i][0];
		}
		else if(data[i][0]+data[i][1]<data[i+1][0])//right
		{
			count++;
			occupy = data[i][0] + data[i][1];
		}
		else //occupies point(not segment)
		{
			occupy = data[i][0];
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	cout << count;
	//system("pause");
	return 0;
}