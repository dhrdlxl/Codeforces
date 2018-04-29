#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int answer = 0;
		int width = 0;
		int view[1001] = { 0, };//각 건물 정보.

		cin >> width;

		for (int j = 0; j < width; j++)
		{
			scanf("%d", &view[j]);
		}
		for(int j=2;j<width-2;j++)
		{
			if (view[j] != 0)
			{
				int minimum = 255;
				for (int z = -2; z <= 2; z++)
				{
					int check = view[j] - view[j + z];
					if ( check < 0)//주위에 현재 건물보다 높은 건물이 있을 때.
					{
						minimum = 0;
						break;
					}
					else if(z!=0)
					{
						if (check < minimum) minimum = check;
					}
				}
				answer += minimum;
			}
		}
		cout << "#" << i << " " << answer << endl;
	}
	
	return 0;
}