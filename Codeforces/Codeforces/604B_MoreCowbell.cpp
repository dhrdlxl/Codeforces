#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, k;
stack<int> a;
vector<int> b;
int main()
{
	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (i < n - k)//�й��ؾ� �ϴ� ��
		{
			a.push(x);
		}
		else//������ ��
		{
			b.push_back(x);
		}
	}
	if (n < k)//�ڽ������� ��ǰ���� ������ ��ǰ������ŭ���� ���ش�.
		k = n;

	int size = a.size();
	int max = b[k - 1];//���� �������� ���� ũ�Ƿ�.
	int num = 0;
	for (int i =0; i <size ; i++)
	{
		num = a.top();//���ÿ� �ִ� �� �� ���� ū ��
		a.pop();
		b[i] += num;
		if (max < b[i])max = b[i];
	}
	cout << max << endl;
	//system("pause");
	return 0;
}