#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, a[104], visited[104], cnt;
vector<int> v;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (!visited[a[i]])
		{
			if (v.size() == n) // ��Ƽ���� �� �� ����
			{
				int lastIdx = 0; // ���� �� �̷��� �����Ǵ� Idx
				int pos;
				for (int ele : v)
				{
					int herePick = 987654321;
					for (int j = i + 1; j < k; j++) // �̷��� ���� ���� �ʰ� �����Ǵ� ��
					{
						if (ele == a[j])
						{
							herePick = j;
							break;
						}
					}
					if (lastIdx < herePick)
					{
						lastIdx = herePick;
						pos = ele;
					}
				}
				visited[pos] = 0;
				cnt++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}

	cout << cnt << '\n';
}