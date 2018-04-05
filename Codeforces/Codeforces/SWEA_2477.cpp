#include <iostream>
#include <vector>//vector
#include <utility>//make_pair, pair
#include <queue>
using namespace std;

int main()
{
	int T;//
	cin >> T;
	for (int x = 1; x < T+1; x++)
	{
		int N, M, K, A, B;
		cin >> N >> M >> K >> A >> B;
		int a_tick[10] = { 0, };//ù ��° â�� �̿�ð� ������ �迭
		int b_tick[10] = { 0, };//�� ��° â�� �̿�ð� ������ �迭
		int t[1001] = { 0, };//�� �����ð� ������ �迭
		for (int i = 1; i < N + 1; i++)//ù ��° â�� �̿�ð�
		{
			scanf_s("%d", &a_tick[i]);
		}
		for (int i = 1; i < M + 1; i++)//�� ��° â�� �̿�ð�
		{
			scanf_s("%d", &b_tick[i]);
		}
		for (int i = 1; i < K + 1; i++)
		{
			scanf_s("%d", &t[i]);
		}
		//������� �Է¹޴´�.

		queue<int> que1;//ù ��° â�� ��⿭
		queue<int> que2;//�� ��° â�� ��⿭

		vector<vector<pair<int, int>>> a(N + 1);//ù ��° â�� ���� ����
		//a = vector<vector<pair<int, int>>>(N + 1);
		vector<vector<pair<int, int>>> b(M + 1);//�� ��° â�� ���� ����



		int tick = 0;//�ð��� �帧.
		int j = 1;//ù��° â�� ��⿭�� �� �� �� ����

		int answer[1001] = {0,};//���� �ش� â���� �̿��ϸ� +1 �� �迭
		int counter = 0;

		//���� �ùķ��̼� �κ�.
		while (counter < K) {
			for (; t[j] == tick;) {//���� ���������� ť�� ����.
				que1.push(j);
				j++;
			}

			for (int i = 1; i < N + 1; i++)//ù��° â�� Ž��
			{
				if (a[i].size() == 1)//���� ó������ â���̸�
				{
					if (tick - a[i][0].second == a_tick[i])//����ð� - ���� ���� �ð� == â�� ó���ð�
					{//�� ó�� �Ϸ����� ��
						que2.push(a[i][0].first);//�� ��° â�� ��⿭�� ����
						a[i].pop_back();//ù��° �ش� â���� �� ����
					}
				}
				if (a[i].size() == 0)//â���� ���� ���� ��.
				{
					if (que1.size() > 0)//��ٸ��� ����ڰ� ������
					{
						a[i].push_back(make_pair(que1.front(), tick));//���� ���� �� ��, ���� �ð��� �ѱ��.
						if (i == A)//�н� ���� ���� â���̸�
						{
							answer[que1.front()]++;//�ش� �մ��� �� 1����.(2�� �Ǹ� �������� ��������.)
						}
						que1.pop();//���� â���� �����Ƿ� ��⿭���� ����
					}
				}
			}

			//�� ��° â������ ������ counter++ ������.
			for (int i = 1; i < M + 1; i++)//�ι� ° â�� Ž��.
			{
				if (b[i].size() == 1)//���� ó������ â���̸�
				{
					if (tick - b[i][0].second == b_tick[i])//����ð� - ���� ���� �ð� == â�� ó���ð�
					{//�� ó�� �Ϸ����� ��
						b[i].pop_back();//�ι�° �ش� â���� �� ����
						counter++;//���� �� ������ ��������.
					}
				}
				if (b[i].size() == 0)//â���� ���� ���� ��.
				{
					if (que2.size() > 0)//�ι�° â���� ��ٸ��� ����ڰ� ������
					{
						b[i].push_back(make_pair(que2.front(), tick));//���� ���� �� ��, ���� �ð��� �ѱ��.
						if (i == B)//�н� ���� ���� â���̸�
						{
							answer[que2.front()]++;//�ش� �մ��� �� 1����.(2�� �Ǹ� �������� ��������.)
						}
						que2.pop();//���� â���� �����Ƿ� ��⿭���� ����
					}
				}
			}
			//�ð� ����
			tick++;
		}
		
		int sum = 0;
		for (int i = 1; i < 1001; i++)
		{
			if (answer[i] == 2) sum += i;
		}
		if (sum == 0)
			sum = -1;
		
		cout << "#" << x << " " << sum<<endl;
	}
	

	system("pause");
	return 0;
}