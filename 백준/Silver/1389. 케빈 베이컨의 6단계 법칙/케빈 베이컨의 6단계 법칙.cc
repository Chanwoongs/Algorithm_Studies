#include<iostream>

using namespace std;

#define INF 99999999

int n, m, a, b, res = 0;
int adj[104][104];

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (i == j)
            {
				adj[i][j] = 0;
            }
            else if(adj[i][j] != 1) 
            {
                adj[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (adj[i][k] + adj[k][j] < adj[i][j]) 
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int min = INF;
    for (int i = 1; i <= n; i++) 
    {
        int sum = 0;
        for (int j = 1; j <= n; j++) 
        {
            sum += adj[i][j];
        }

        if (sum < min) 
        {
            min = sum;
            res = i;
        }
    }

    cout << res << '\n';

    return 0;
}