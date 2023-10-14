#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int a[54][54];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;

    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
        {
            rectangle[i][j] = rectangle[i][j] * 2;
        }

        pair<int, int> ld = { rectangle[i][1], rectangle[i][0] };
        pair<int, int> ru = { rectangle[i][3], rectangle[i][2] };

        for (int j = ru.first; j <= ld.first; j++)
        {
            for (int k = ld.first; k <= ru.first; k++)
            {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < rectangle.size(); i++)
    {

        pair<int, int> ld = { rectangle[i][1] - 1, rectangle[i][0] + 1 };
        pair<int, int> ru = { rectangle[i][3] + 1, rectangle[i][2] - 1 };

        for (int j = ru.first; j <= ld.first; j++)
        {
            for (int k = ld.first; k <= ru.first; k++)
            {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return answer;
}