#include <iostream>
#include <vector>
using namespace std;

struct Quest
{
	int STR, INT, PNT;
};

int n, res;
vector<Quest> a;
int dp[1004][1004];
int visited[104];

int rpg(int STR, int INT)
{
	int& res = dp[STR][INT];
	if (res != -1) return res;

	res = 0;
	int pnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (a[i].STR <= STR || a[i].INT <= INT)
		{
			res++;
			if (!visited[i])
			{
				visited[i] = true;
				pnt += a[i].PNT;
				v.push_back(i);
			}
		}
	}

	for (int i = 0; i < pnt; i++)
	{
		int nextSTR = min(1000, STR + i);
		int nextINT = min(1000, INT + pnt - i);
		res = max(res, rpg(nextSTR, nextINT));
	}

	for (int here : v)
		visited[here] = false;

	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int STR, INT, PNT;
		scanf("%d %d %d", &STR, &INT, &PNT);
		a.push_back({ STR, INT, PNT });
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", rpg(1, 1));
}