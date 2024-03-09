#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct stu
{
    int num;
    unordered_set<int> like;
};

const int dy[] = { 1, 0, -1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, res, temp;
stu map[24][24];
vector<stu> studs(404);

void findSeat(stu stud)
{
    // y, x는 최종적으로 학생이 배치될 좌표
    // maxL 인접한 좋아하는 사람 수
    // maxB 인접한 빈칸 수
    int y = 0, x = 0, maxL = -1, maxB = -1; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // max 값을 -1로 초기화하지 않으면 마지막 학생이 아래 예외 처리에서 0,0으로 확정된다.
            if (map[i][j].num != 0) continue;

            // 1번 규칙 : 빈칸 중 좋아하는 학생 가장 많이 인접한 칸
            int likeCnt = 0, blankCnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (stud.like.find(map[ny][nx].num) != stud.like.end()) likeCnt++;
                else if (map[ny][nx].num == 0) blankCnt++;
            }
            // 여기까지 하면 현재 칸의 좋아요수와 빈칸 수 얻음
            if (maxL < likeCnt)
            {
                maxL = likeCnt, y = i, x = j, maxB = blankCnt;                
            }
            // 2번 규칙
            else if (maxL == likeCnt) // 인접한 좋아하는 사람 최대가 같은 경우
            {
                if (maxB < blankCnt)
                    maxB = blankCnt, y = i, x = j;
                // 3번 규칙
                else if (maxB == blankCnt)
                {
                    if (i < y)
                        y = i, x = j;
                    else if (i == y)
                    {
                        if (j < x)
                            y = i, x = j;
                    }
                }
            }
        }
    }
    map[y][x] = stud;
}

int calc()
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

                if (map[i][j].like.find(map[ny][nx].num) != map[i][j].like.end())
                    cnt++;
            }
            switch (cnt)
            {
            case 0: break;
            case 1: res += 1; break;
            case 2: res += 10; break;
            case 3: res += 100; break;
            case 4: res += 1000; break;
            }
        }
    }
    return res;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> temp;
        studs[i].num = temp;
        for (int j = 0; j < 4; j++)
        {
            cin >> temp;
            studs[i].like.insert(temp);
        }

        findSeat(studs[i]);
    }

    cout << calc() << '\n';
}