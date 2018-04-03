#include <iostream>
#include <map>//using map
using namespace std;

int n;//number of students
int check[1000001];
map<int, int> mp;

int main()
{
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		check[x]++;
		check[y]--;
		mp[x] = y;
	}

	int start;
	for (int i = 0; i < 1000001; i++)//find first
	{
		if (check[i] == 1) {
			start = i;
			break;
		}
	}

	int key = start;
	int key2= 0;

	cout << key << " ";

	bool end = false;
	while (1)
	{
		key2 = mp.find(key2)->second;
		if (key2 != 0)
			cout << key2 << " ";
		else
			break;
	
		key = mp.find(key)->second;
		if (key != 0)
			cout << key << " ";
		else
			break;
	}


	//system("pause");
	return 0;
}