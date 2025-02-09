#include <iostream>

using namespace std;

#define INF 99999999

int n, a;
int adj[104][104];

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            adj[i][j] = a; 
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] == 1 && adj[k][j] == 1) 
                {
                    adj[i][j] = 1; 
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
