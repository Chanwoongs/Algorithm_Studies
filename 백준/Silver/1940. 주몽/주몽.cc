#include <iostream>
#include <map>

using namespace std;

int cnt;
int trg;
map<int, int> mat;  
int res;
int num;

int main()
{
    cin >> cnt >> trg;

    for (int i = 1; i <= cnt; i++)
    {
        int temp;
        cin >> temp; 
        mat[temp]++;
    }
	for(auto it : mat)
    { 
		if(trg - it.first > 0 && mat[trg - it.first] > 0)
        { 
			res += min(mat[it.first], mat[trg - it.first]);
		} 
	}  
    cout << res / 2 << '\n';
}