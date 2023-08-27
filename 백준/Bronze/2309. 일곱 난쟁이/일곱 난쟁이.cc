#include <iostream>
#include <vector>
#include <algorithm>
//#include <pair>
using namespace std;

int a[100004];
int all;
int fake1;
int fake2;
vector<int> v;
//pair<int, int> fake;

void findFake()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (all - a[i] - a[j] == 100)
            {
                fake1 = a[i];
                fake2 = a[j];
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
        if (a[i] == fake1 || a[i] == fake2) continue;
        v.push_back(a[i]);
    }
    
    sort(v.begin(), v.end());
    
    for (int num : v) 
    {
        cout << num << '\n';
    }
}  
  