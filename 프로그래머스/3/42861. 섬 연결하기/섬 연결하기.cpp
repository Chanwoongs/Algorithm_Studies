#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[104];

int find(int x)
{
    if (parent[x] == x) return x;
    else return find(parent[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x != y) parent[x] = y;
}

bool cmpParent(int x, int y)
{
    if (find(x) == find(y)) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < 104; i++)
        parent[i] = i;
    
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b)
         {
            return a[2] < b[2];
         });
    
    for (int i = 0; i < costs.size(); i++)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        
        if (!cmpParent(a, b))
        {
            merge(a, b);
            answer += c;
        }
    }
    
    return answer;
}