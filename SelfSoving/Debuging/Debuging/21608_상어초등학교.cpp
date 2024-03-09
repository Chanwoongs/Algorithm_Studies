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
    // y, x�� ���������� �л��� ��ġ�� ��ǥ
    // maxL ������ �����ϴ� ��� ��
    // maxB ������ ��ĭ ��
    int y = 0, x = 0, maxL = -1, maxB = -1; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // max ���� -1�� �ʱ�ȭ���� ������ ������ �л��� �Ʒ� ���� ó������ 0,0���� Ȯ���ȴ�.
            if (map[i][j].num != 0) continue;

            // 1�� ��Ģ : ��ĭ �� �����ϴ� �л� ���� ���� ������ ĭ
            int likeCnt = 0, blankCnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (stud.like.find(map[ny][nx].num) != stud.like.end()) likeCnt++;
                else if (map[ny][nx].num == 0) blankCnt++;
            }
            // ������� �ϸ� ���� ĭ�� ���ƿ���� ��ĭ �� ����
            if (maxL < likeCnt)
            {
                maxL = likeCnt, y = i, x = j, maxB = blankCnt;                
            }
            // 2�� ��Ģ
            else if (maxL == likeCnt) // ������ �����ϴ� ��� �ִ밡 ���� ���
            {
                if (maxB < blankCnt)
                    maxB = blankCnt, y = i, x = j;
                // 3�� ��Ģ
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