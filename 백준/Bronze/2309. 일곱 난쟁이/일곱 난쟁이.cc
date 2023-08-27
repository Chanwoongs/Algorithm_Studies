#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int a[100004];
int all;
vector<int> v;
pair<int, int> fake;

void findFake()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (all - a[i] - a[j] == 100)
            {
                fake = {i, j};
                return;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        all += a[i];
    }
    
    findFake();
    for (int i = 0; i < 9; i++)
    {
        if (i == fake.first || i == fake.second) continue;
        v.push_back(a[i]);
    }
    
    sort(v.begin(), v.end());
    
    for (int num : v) 
    {
        cout << num << '\n';
    }
}  
  