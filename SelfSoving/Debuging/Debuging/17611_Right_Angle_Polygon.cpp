#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define y1 cc
vector<int> check_x, check_y;
int n, x, y, x1, y1, x2, y2, _y[1000004], _x[1000004], res;
pair<int, int> a[100004];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		// 음수 때문에 좌표이동
		x += 500000;
		y += 500000;
		a[i] = { x, y };
		check_x.push_back(x);
		check_y.push_back(y);
	}
	 
	// 처음 꼭짓점과 마지막 꼭짓점을 연결
	a[n] = a[0];
	for (int i = 0; i < n; i++)
	{
		// 현재 변을 구성하는 두 꼭짓점의 좌표
		tie(x1, y1) = a[i];
		tie(x2, y2) = a[i + 1];

		if (x1 != x2) // 변이 수평이라면
		{
			if (x1 > x2) swap(x1, x2);
			for (int j = x1 + 1; j <= x2; j++)
			{
				_x[j]++;
			}
		}
		if (y1 != y2) // 변이 수직이라면
		{
			if (y1 > y2) swap(y1, y2);
			for (int j = y1 + 1; j <= y2; j++)
			{
				_y[j]++;
			}
		}
	}
	for (int a : check_y) res = std::max(res, _y[a]);
	for (int a : check_x) res = std::max(res, _x[a]);
	cout << res << '\n';
}