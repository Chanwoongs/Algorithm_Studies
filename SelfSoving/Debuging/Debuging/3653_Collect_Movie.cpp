#include <iostream>
#include <map>
#include <cstring>

using namespace std;
int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int idx, int value)
{
	while (idx <= 200004)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
	return;
}

int sum(int idx)
{
	int res = 0;
	while (idx > 0)
	{
		res += tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		int updateIdx = 100001;
		for (int i = 1; i <= n; i++)
		{
			update(i + updateIdx, 1);
			mp[i] = i + updateIdx;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			int idx = mp[temp];
			cout << sum(idx) - 1 << ' ';
			update(idx, -1); // DVD가 케이스에서 빠져 나갔다.
			update(--updateIdx, 1); // 제일 첫 위치(상단에) DVD를 놓는다.
			mp[temp] = updateIdx; // mp에 저장된 위치를 맨 앞으로 다시 저장한다.
		}
		cout << '\n';
	}
}