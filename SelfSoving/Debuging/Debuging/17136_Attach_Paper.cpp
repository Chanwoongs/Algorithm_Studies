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
	// Ž�� �ϴٰ� ����� �����̰� ����� ����� �����̺��� Ŀ���� Ž�� X
	if (cnt >= res) return; 
	 
	// ���η� Ž���ϴ� ��踦 �Ѿ�� ���� �� Ž��
	if (x == n)
	{
		DFS(y + 1, 0, cnt);
		return;
	}
	// ��� �� Ž�� �Ϸ�
	if (y == n)
	{
		res = min(cnt, res);
		return;
	}
	// ������ �ʾƵ� �Ǵ� ����
	if (a[y][x] == 0)
	{
		DFS(y, x + 1, cnt);
		return;
	}

	for (int _size = 5; _size >= 1; _size--)
	{
		if (mp[_size] == 5) continue; // 5���� �Ѱ� ���� �� ����
		if (check(y, x, _size)) // ������ ���� �� �ִ��� üũ
		{
			mp[_size]++; // ���δ�
			draw(y, x, _size, 0); // ���� ���� 0���� �����
			DFS(y, x + _size, cnt + 1); // ����ؼ� ���� Ž��
			draw(y, x, _size, 1); // ����
			mp[_size]--; // ����
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