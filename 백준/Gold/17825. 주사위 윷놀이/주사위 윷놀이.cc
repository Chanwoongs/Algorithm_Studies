#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int a[14], mal[4], n = 10;
int v[104];
vector<int> adj[54];

int move(int here, int cnt)
{
	if (here == 100) return 100; // 도착했다
	if (adj[here].size() >= 2) // 파란색 칸에서 이동을 시작한다면
	{
		here = adj[here][1]; // 파란 길을 따라간다 (한칸만)
		cnt--;
	}
	if (cnt)
	{
		// 말을 주사위로 나온 수만큼 움직인다
		queue<int> q;
		q.push(here);
		int there;
		while (q.size())
		{
			int x = q.front();
			q.pop();
			there = adj[x][0];
			q.push(there);
			if (there == 100) break;
			cnt--;
			if (cnt == 0) break;
		}
		return there;
	}
	else return here;
}

bool isMal(int malIdx, int idx)
{
	if (malIdx == 100) return false;
	for (int i = 0; i < 4; i++)
	{
		if (i == idx) continue;
		if (mal[i] == malIdx) return true; // 말이 있다면
	}
	return false;
}

void add(int here, int there) 
{
	adj[here].push_back(there);
}

void setMap() 
{
	for (int i = 0; i <= 19; i++) add(i, i + 1);
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);

	add(10, 27); add(27, 28); add(28, 24); add(24, 25);
	add(25, 26); add(26, 20); add(20, 100);

	v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10;
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
	v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25;
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
	v[29] = 28; v[30] = 27; v[31] = 26;
}

int go(int here)
{
	if (here == n) return 0; // 10턴을 다 사용했다면
	int res = 0;

	for (int i = 0; i < 4; i++)
	{
		int tempIdx = mal[i]; // 현재 말의 위치 저장
		int malIdx = move(tempIdx, a[here]); // 주사위를 굴려 말을 이동

		if (isMal(malIdx, i)) continue; // 갈 위치에 말이 이미 있다면

		mal[i] = malIdx; // 갈 곳으로 위치 변경
		res = std::max(res, go(here + 1) + v[malIdx]); // 현재 말의 위치에 값을 더해 go
		mal[i] = tempIdx; // 원복
	}
	return res;
}

int main()
{
	setMap();
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << go(0) << '\n';
}