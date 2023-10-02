#include <iostream>
#include <map>


using namespace std;

const int INF = 99999999;
int a[104][104], res = INF, n = 10;
map<int, int> mp;

bool check(int y, int x, int size)
{
	if (y + size > n || x + size > n) return false;

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (a[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int size, int value)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			a[i][j] = value;
		}
	}
}

void DFS(int y, int x, int cnt)
{
	// 탐색 하다가 사용할 색종이가 결과에 저장된 색종이보다 커지면 탐색 X
	if (cnt >= res) return; 
	 
	// 가로로 탐색하다 경계를 넘어가면 다음 줄 탐색
	if (x == n)
	{
		DFS(y + 1, 0, cnt);
		return;
	}
	// 모두 다 탐색 완료
	if (y == n)
	{
		res = min(cnt, res);
		return;
	}
	// 붙이지 않아도 되는 지점
	if (a[y][x] == 0)
	{
		DFS(y, x + 1, cnt);
		return;
	}

	for (int _size = 5; _size >= 1; _size--)
	{
		if (mp[_size] == 5) continue; // 5개를 넘게 붙일 수 없다
		if (check(y, x, _size)) // 색종이 붙일 수 있는지 체크
		{
			mp[_size]++; // 붙인다
			draw(y, x, _size, 0); // 붙인 곳을 0으로 만든다
			DFS(y, x + _size, cnt + 1); // 계속해서 다음 탐색
			draw(y, x, _size, 1); // 원복
			mp[_size]--; // 땐다
		}
 	}
	return;
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	DFS(0, 0, 0);
	cout << (res == INF ? -1 : res) << '\n';
}