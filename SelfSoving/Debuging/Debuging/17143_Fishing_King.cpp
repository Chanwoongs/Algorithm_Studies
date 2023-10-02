#include <iostream>
#include <vector>
#include <cstring>
#define max_n 100
using namespace std;

struct Shark {
	int y, x, s, dir, z, death; // ���� ���� �����ľ� �Ѵ�
}a[max_n * max_n];

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
int shark[max_n][max_n], R, C, M, res, temp[max_n][max_n];

int main()
{
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y--;
		a[i].x--;
		a[i].dir--;

		// ������ 0, 1�̶�� ���Ʒ�
		if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
		// ������ 2, 3�̶�� �¿�
		else a[i].s %= (2 * (C - 1));

		shark[a[i].y][a[i].x] = i;
	}
	
	// ��� ������
	for (int t = 0; t < C; t++)
	{
		// ��� ���
		for (int y = 0; y < R; y++) // ���η� ����
		{
			if (shark[y][t]) // ���� ���� �߰��� ���
			{
				a[shark[y][t]].death = 1;
				res += a[shark[y][t]].z;
				shark[y][t] = 0;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= M; i++) // ��� ������
		{
			if (a[i].death) continue;

			// �߰����� ����
			int y = a[i].y;
			int x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny, nx;

			while (1) // ���� ���������� �ִ� 2���� �۵��� (���� 2�� �ε����� ���)
			{
				ny = y + s * dy[d];
				nx = x + s * dx[d];

				// ���� �ε����� �ʴ� ��� break
				if (ny >= 0 && nx >= 0 && ny < R && nx < C) break; 

				// ������ ����� ���
				if (d <= 1)
				{
					if (ny < 0)
					{
						s -= y;
						y = 0;
					}
					else
					{
						s -= R - 1 - y;
						y = R - 1;
					}
				}
				else
				{
					if (nx < 0) // �������� ������ ���
					{
						s -= x;
						x = 0;
					}
					else
					{
						s -= C - 1 - x;
						x = C - 1;
					}
				}
				d ^= 1; // 3 <-> 2, 0 <-> 1
			}

			if (temp[ny][nx]) // �� ��ĥ ��� 
			{
				if (a[temp[ny][nx]].z < a[i].z) // ������ ���� ���� ���� ��� ũ�� ��
				{
					a[temp[ny][nx]].death = 1;
					temp[ny][nx] = i;
				}
				else a[i].death = 1;
			}
			else temp[ny][nx] = i;

			// ���������� �ű��
			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		memcpy(shark, temp, sizeof(shark));
	}
	cout << res << '\n';
}