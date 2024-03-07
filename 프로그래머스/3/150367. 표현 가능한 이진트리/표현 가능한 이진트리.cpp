#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string cvrtTwo(long long num)
{
    string temp = "";
    
    while (num > 0)
    {
        temp = to_string(num % 2) + temp;
        num /= 2;
    }
    
    return temp;
}

void makePerfBT(string& s)
{
    int height = 0;
    while (static_cast<int>(pow(2, height)) - 1 < s.size())
    {
        height++;
    }
    
    int nodes = static_cast<int>(pow(2, height)) - 1;
    
    while (s.length() < nodes)
    {
        s = '0' + s;
    }
}


bool check(string s)
{
    if (s.length() == 1 || s.find('1') == string::npos) return true;
    
    int mid = s.length() / 2;
    string l = s.substr(0, mid);
    string r = s.substr(mid + 1);
    
    if (s[mid] == '1' && check(l) && check(r)) return true;
    else return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size());
    vector<string> twoDigits(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++)
    {
        twoDigits[i] = cvrtTwo(numbers[i]);
        makePerfBT(twoDigits[i]);
        answer[i] = check(twoDigits[i]) ? 1 : 0;
    }
    
    return answer;
}