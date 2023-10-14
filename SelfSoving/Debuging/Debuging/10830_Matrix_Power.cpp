#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
ll n, b;

matrix operator*(const matrix& a, const matrix& b)
{
    matrix res(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }

    return res;
}

matrix power(matrix& a, ll b)
{
    matrix res(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            b -= 1;
            res = res * a;
        }
        else
        {
            b /= 2;
            a = a * a;
        }
    }
    return res;
}

void printMatrix(const matrix& a) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> n >> b;

    matrix m(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    m = power(m, b);
    printMatrix(m);
}