#include <iostream>
#include <cmath>
using namespace std;

#define y1 aaa

double x1, x2, y1, y2, r1, r2, n;
double res;

double power(int a)
{
    return a * a;
}

double dist(double a, double b, double c, double d)
{
    return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2)
        {
            cout << 0 << '\n';
            continue;
        }

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << -1 << '\n';
            continue;
        }

        if (dist(x1, y1, x2, y2) > r1 + r2) res = 0;
        else if (dist(x1, y1, x2, y2) == r1 + r2) res = 1;
        else if (dist(x1, y1, x2, y2) < r1 + r2) res = 2;



        cout << res << '\n';
    }
}