#include <iostream>
using namespace std;

int a[3], sum;
bool isEq;

int main()
{
    isEq = true;
    
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        if (a[i] != 60) isEq = false;
        sum += a[i];
    }
    
    if (isEq) 
    {
        cout << "Equilateral" << '\n';
    }
    else if (sum != 180)
    {
        cout << "Error" << '\n';
    }
    else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) 
    {
        cout << "Isosceles" << '\n'; 
    }
    else
    {
        cout << "Scalene" << '\n';
    }
    
    return 0;
}