#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int idx;
    
    cin >> str;
    cin >> idx;
    
    cout << str.at(idx - 1);
}