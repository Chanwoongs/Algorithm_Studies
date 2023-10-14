#include <iostream>
#include <vector>

using namespace std;

int t, n, k = 3;
int res = 987654321;
vector<string> vec;

int solve(vector<string> v)
{
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int diff = 0;
            for (int k = 0; k < v[i].size(); k++)
            {
                if (v[i][k] != v[j][k]) diff++;
            }
            sum += diff;
        }
    }
    return sum;
}

void combi(int start, vector<string> v)
{
    if (v.size() == k)
    {
        res = std::min(res, solve(v));
        return;
    }
    for (int i = start + 1; i < n; i++)
    {
        v.push_back(vec[i]);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        vector<string> vv;
        res = 987654321;
        
        cin >> n;
        vec.clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            vec.push_back(s);
        }
        if (n >= 33)
        {
            cout << 0 << '\n';
            continue;
        }
        combi(-1, vv);

        cout << res << '\n';
    }
}