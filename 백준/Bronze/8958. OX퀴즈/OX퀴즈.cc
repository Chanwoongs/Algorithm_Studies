#include <iostream>
#include <string>
using namespace std;

int evaluateScore(string results)
{
    int totalScore = 0;
    int score = 0;
    bool combo = false;

    for (auto result : results)
    {
        // case X:
        if (result == 'X')
        {
            combo = false;
            score = 0;
            continue;
        }

        // case O:
        if (combo)
        {
            score += 1;
            totalScore += score;
        }
        else
        {
            score = 1;
            totalScore += score;
            combo = true;
        }
    }

    return totalScore;
}

int main()
{
    int n;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        cout << evaluateScore(str) << '\n';
    }
}