#include <iostream>
#include <vector>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 , -1 };
int n, m, mini = 10000004, result = 99999999;
int a[54][54], visited[54][54];
vector<vector<int>> realChList;
vector<pair<int, int>> chList;
vector<pair<int, int>> hoList;
vector<pair<int, int>> ch;
vector<pair<int, int>> pick;

void combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		realChList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chList.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				hoList.push_back({ i, j });
			}
			else if (a[i][j] == 2)
			{
				chList.push_back({ i, j });
			}
		}
	}

	vector<int> v;
	combi(-1, v);

	for (vector<int> cList : realChList) // 3개씩 뽑힌 Index들 ( ( 1, 2, 3 ), ( 2, 2 ), ( 3, 3 ) ) 
	{
		int res = 0;

		for (pair<int, int> ho : hoList)
		{
			int min = 99999999;
			for (int ch : cList) // ( 1, 1 )
			{
				int dist = abs(ho.first - chList[ch].first) + abs(ho.second - chList[ch].second);
				if (min > dist) min = dist;
			}
			res += min;
		}
		if (result > res) result = res;
	}
	cout << result << '\n';
}