#include <iostream>
#include <vector>

using namespace std;

int n, res = 987654321;
int s[24][24];

int go(vector<int> start, vector<int> link)
{
	pair<int, int> res;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			if (i == j) continue; // (i, i)�̸� 0 �̱� ������

			res.first += s[start[i]][start[j]];
			res.second += s[link[i]][link[j]];
		}
	}
	return abs(res.first - res.second);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		// 0, 1 �� ��Ȯ�� ������ �ɰ��� �ֳ�
		if (__popcnt(i) != n / 2) continue; 
		
		vector<int> start, link;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) start.push_back(j); // 1�� �����ִ�.
			else link.push_back(j);
		}
		res = std::min(res, go(start, link));
	}
	cout << res << '\n';
}