#include <iostream>

using namespace std;

int cnt;
int trg;
int mat[15004];
int res;

int main()
{
    cin >> cnt >> trg;

    for (int i = 0; i < cnt; i++)
    {
        cin >> mat[i]; 
    }
    
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (mat[i] + mat[j] == trg) res++;
        }
    }
    
    cout << res << '\n';
}