#include <iostream>
#include <algorithm>//using sort
#include <utility>//using pair, make_pair
using namespace std;

int n;//1~5000
pair<int, int> ab[5001];

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)//when first factor is same
		return a.second < b.second; //compare second factor , sort in Ascending order
	return a.first < b.first; // general case, sort in Ascending order
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		ab[i] = make_pair(a, b);
	}
	sort(ab, ab + n, compare);

	int save = 0;
	for (int i = 0; i<n; i++)
	{
		if (min(ab[i].first, ab[i].second) >= save)
			save = min(ab[i].first, ab[i].second);
		else
			save = max(ab[i].first, ab[i].second);
	}

	cout << save << endl;
	//system("pause");
	return 0;
}