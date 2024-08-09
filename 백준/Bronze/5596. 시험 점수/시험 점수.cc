#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int a, b = 0, c = 0; // 초기화
    while (cin >> a)
    {
        v.push_back(a);
    }
    
    for (int i = 0; i < v.size() / 2; i++)
    {
        b += v[i]; 
    }
    for (int i = v.size() / 2; i < v.size(); i++)
    {
        c += v[i]; 
    }
    
    if (b < c)
    {
        cout << c << '\n';
    }
    else 
    {
        cout << b << '\n';
    }

    return 0;
}