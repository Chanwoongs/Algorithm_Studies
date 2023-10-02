#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt;
vector <int> v;

int main() 
{
    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int s = 0;
    while (v.size() != s + 1) 
    {

        v[v.size() - 2] += v[v.size() - 1]; // 맨뒤에 2개 연결
        v.pop_back();

        v[s]--;
        if (v[s] == 0)
            s++;
        cnt++;
    }

    cout << cnt;
}