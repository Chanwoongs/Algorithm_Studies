#include<iostream>
#include<map>
#include<string>

using namespace std;

int cnt, prob;
map<string, int> dic;
string names[100004];
string temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> cnt >> prob;
    
    for (int i = 1; i <= cnt; i++)
    {
        cin >> temp;
        dic[temp] = i;
        //dic.insert(pair<string, int>(temp, i));
        names[i] = temp;
    }
    
    for (int i = 0; i < prob; i++)
    {
        cin >> temp;
        
        int num = atoi(temp.c_str());
        
        if (num == 0)
            cout << dic[temp] << '\n';
            //cout << dic.find(temp)->second << '\n';
        else
            cout << names[num] << '\n';
    }
}