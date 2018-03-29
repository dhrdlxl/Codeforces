#include <iostream>
#include <cmath>//sqrt, ceil
using namespace std;

int r;
int x;
int y;
int x_1;
int y_1;

int main()
{
	cin >> r >> x >> y >> x_1 >> y_1;
	double length = sqrt((double)(x - x_1)*(x-x_1) + (double)(y-y_1)*(y-y_1));
	
	cout << ceil(length / (2 * r));

	//system("pause");
	return 0;
}