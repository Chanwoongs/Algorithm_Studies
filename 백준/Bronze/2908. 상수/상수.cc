#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

bool cmp(string& a, string& b)
{
    if (a.size() > b.size()) return true;
    
    return a > b;
}

int main()
{
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    if (cmp(a, b)) cout << a << '\n';
    else cout << b << '\n';
}