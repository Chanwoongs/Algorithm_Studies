#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    int n = s.length();
    bool res[304] = { false, };
    res[0] = true;

    for (auto& w : wordDict)
    {
        dict.insert(w);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto& word : wordDict)
        {
            int wordLen = word.length();
            int prevIdx = i - wordLen;
            if (prevIdx < 0) continue;
            if (!res[prevIdx]) continue;

            string temp = s.substr(prevIdx, wordLen);
            cout << "temp = " << temp << '\n';
            if (temp.size() != word.size()) continue;

            cout << temp << ' ' << word << '\n';
            if (temp == word)
            {
                res[i] = true;
                break;
            }
        }
        for (int j = 0; j <= n; j++)
        {
            cout << res[j] << ' ';
        }
        cout << '\n';
        cout << '\n';
    }
    return res[n];
}

int main()
{
    vector<string> w;;
    w.push_back("e");
    w.push_back("no");
    w.push_back("cop");
    cout << wordBreak("nocope", w) << '\n';

}
