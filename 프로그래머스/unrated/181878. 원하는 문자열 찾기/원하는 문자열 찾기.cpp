#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (auto &c : myString)
    {
        if (c > 'Z') c -= 'a' - 'A';
    }
    for (auto &c : pat)
    {
        if (c > 'Z') c -= 'a' - 'A';
    }
    
    cout << myString << pat;
    
    if (myString.find(pat) != string::npos) answer = 1;
    else answer = 0;
    
    return answer;
}