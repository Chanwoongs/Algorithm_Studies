#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char a[104][104];
int res[104][104];
int h, w;
vector<int> v;
string s;

int main()
{
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf(" %c", &a[i][j]);

	for (int i = 0; i < h; i++)
	{
		int	cldIdx = -1;
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == 'c')
			{
				cldIdx = j;
				res[i][j] = 0;
			}
			else
			{
				if (cldIdx == -1) res[i][j] = -1;
				else res[i][j] = j - cldIdx;
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}