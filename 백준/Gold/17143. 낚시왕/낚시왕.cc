#include <iostream>
#include <vector>
#include <cstring>
#define max_n 100
using namespace std;

struct Shark {
	int y, x, s, dir, z, death; // 죽은 상어는 지나쳐야 한다
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

		// 방향이 0, 1이라면 위아래
		if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
		// 방향이 2, 3이라면 좌우
		else a[i].s %= (2 * (C - 1));

		shark[a[i].y][a[i].x] = i;
	}
	
	// 사람 움직임
	for (int t = 0; t < C; t++)
	{
		// 상어 잡기
		for (int y = 0; y < R; y++) // 세로로 본다
		{
			if (shark[y][t]) // 가장 빨리 발견한 상어
			{
				a[shark[y][t]].death = 1;
				res += a[shark[y][t]].z;
				shark[y][t] = 0;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= M; i++) // 상어 움직임
		{
			if (a[i].death) continue;

			// 중간변수 선언
			int y = a[i].y;
			int x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny, nx;

			while (1) // 무한 루프같지만 최대 2번만 작동함 (벽에 2번 부딪히는 경우)
			{
				ny = y + s * dy[d];
				nx = x + s * dx[d];

				// 벽에 부딪히지 않는 경우 break
				if (ny >= 0 && nx >= 0 && ny < R && nx < C) break; 

				// 범위를 벗어나는 경우
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
					if (nx < 0) // 좌측으로 범위를 벗어남
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

			if (temp[ny][nx]) // 상어가 겹칠 경우 
			{
				if (a[temp[ny][nx]].z < a[i].z) // 움직일 곳의 상어와 현재 상어 크기 비교
				{
					a[temp[ny][nx]].death = 1;
					temp[ny][nx] = i;
				}
				else a[i].death = 1;
			}
			else temp[ny][nx] = i;

			// 최종적으로 옮기기
			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		memcpy(shark, temp, sizeof(shark));
	}
	cout << res << '\n';
}