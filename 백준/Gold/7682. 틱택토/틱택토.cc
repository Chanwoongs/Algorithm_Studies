#include <iostream>
#include <string>

using namespace std;

char map[4][4];

bool xWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (map[i][0] == 'X' &&
           map[i][0] == map[i][1] && map[i][1] == map[i][2])
            return true;
        if (map[0][i] == 'X' &&
           map[0][i] == map[1][i] && map[1][i] == map[2][i])
            return true;
    }
    if (map[0][0] == 'X' &&
       map[0][0] == map[1][1] && map[1][1] == map[2][2])
        return true;
    if (map[0][2] == 'X' &&
        map[0][2] == map[1][1] && map[1][1] == map[2][0])
        return true;
    
    return false;
}

bool oWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (map[i][0] == 'O' &&
           map[i][0] == map[i][1] && map[i][1] == map[i][2])
            return true;
        if (map[0][i] == 'O' &&
           map[0][i] == map[1][i] && map[1][i] == map[2][i])
            return true;
    }
    if (map[0][0] == 'O' &&
       map[0][0] == map[1][1] && map[1][1] == map[2][2])
        return true;
    if (map[0][2] == 'O' &&
        map[0][2] == map[1][1] && map[1][1] == map[2][0])
        return true;
    
    return false;
}
    
int main()
{
    while (1)
    {
        string a;
        int x = 0, o = 0;
        cin >> a;
        if (a == "end") break;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                map[i][j] = a[i * 3 + j];
                if (map[i][j] == 'X') x++;
                else if (map[i][j] == 'O') o++;
            }
        }
        
        bool isXWin = xWin();
        bool isOWin = oWin();
        
        if (isXWin && !isOWin && x == o + 1) cout << "valid" << '\n';
        else if (!isXWin && isOWin && x == o) cout << "valid" << '\n';
        else if (!isXWin && !isOWin && x == 5 && o == 4) cout << "valid" << '\n';
        else cout << "invalid" << '\n';
    }
}