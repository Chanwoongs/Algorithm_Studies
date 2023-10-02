#include<iostream>

using namespace std;

int n, a[1001], res = 1, cnt[1001], idx;
int prevList[1001];

void go(int idx)
{
	if (idx == -1) return;
	go(prevList[idx]);
	cout << a[idx] << ' ';
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	fill(prevList, prevList + 1001, -1); // idx 0~n 까지, 따라서 -1로
	fill(cnt, cnt + 1001, 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
			{
				cnt[i] = cnt[j] + 1;
				prevList[i] = j;
				if (res < cnt[i])
				{
					res = cnt[i];
					idx = i; // 마지막 인덱스
				}
			}
		}
	}
	cout << res << '\n';
	go(idx);
}