#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    map<char, int> map;
    std::map<char, int>::iterator iter;

    cin >> str;

    for (auto& let : str)
    {
        if (let >= 'a')
        {
            let -= ('a' - 'A');
        }

        iter = map.find(let);

        if (iter != map.end()) map[iter->first] += 1;
        else map[let] = 1;
    }

    std::map<char, int>::iterator iterMax = map.begin();
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (iterMax->second < it->second) iterMax = it;
    }
    for (auto it = iterMax; it != map.end(); it++)
    {
        if (it->first != iterMax->first && it->second == iterMax->second)
        {
            cout << "?";
            return 0;
        }
    }

    cout << iterMax->first;

    return 0;
}