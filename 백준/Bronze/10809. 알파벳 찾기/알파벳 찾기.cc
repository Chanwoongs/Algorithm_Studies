#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int alphaIndex[26];
    
    cin >> str;
    
    for (int i = 0; i < 26; i++)
    {
        alphaIndex[i] = -1; 
    }
    
    int index = 0;
    for (auto let : str)
    {
        if(alphaIndex[(int)(let - 'a')] == -1) 
        {
            alphaIndex[(int)(let - 'a')] = index;
        }
        index++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << alphaIndex[i] << ' ';
    }
}