#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> v;

void go(int s, int e)
{
    if (s >= e) return;
    if (s == e - 1)
    {
        cout << v[s] << '\n';
        return;
    }

    int next = s + 1;
    while (next < v.size())
    {
        if (v[s] < v[next]) break;
        next++;
    }

    go(s + 1, next);
    go(next, e);
    cout << v[s] << '\n';
}

int main()
{
    while (cin >> num)
    {
        v.push_back(num);
    }
    go(0, v.size());
}