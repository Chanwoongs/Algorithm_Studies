#include <iostream>
#include <string>
using namespace std;

int t;
string str;

int main()
{
    cin >> t;
    
    while (t--)
    {
        cin >> str;
        cout << str[0] << str[str.length()-1] << '\n';
    }
}