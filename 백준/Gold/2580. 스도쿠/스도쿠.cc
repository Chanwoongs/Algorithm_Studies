#include <iostream>

using namespace std;

int map[10][10];
bool row[10][10], col[10][10], square[10][10];

void print() 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void DFS(int cnt) 
{
    if (cnt == 81)
    {
        print();
        exit(0);
    }

    int x = cnt / 9; 
    int y = cnt % 9;
    int n = (x / 3) * 3 + (y / 3);

    if (map[x][y] != 0) 
    {
        return DFS(cnt + 1);
    }
    else 
    {
        for (int i = 1; i <= 9; i++) 
        {
            if (!row[x][i] && !col[y][i] && !square[n][i]) 
            {
                
                row[x][i] = true; col[y][i] = true; square[n][i] = true;
                map[x][y] = i;
                DFS(cnt + 1);
                row[x][i] = false; col[y][i] = false; square[n][i] = false;
                map[x][y] = 0;
            }
        }
    }
}

int main(void) {

    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> map[i][j];

            if (map[i][j] != 0) {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }
    DFS(0);
    return 0;
}