#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a + b > b + a;
}

string go(vector<int> numbers) {
    vector<string> numStrs;
    for (int num : numbers) {
        numStrs.push_back(to_string(num));
    }
    
    sort(numStrs.begin(), numStrs.end(), compare);
    
    if (numStrs[0] == "0") {
        return "0";
    }
    
    string answer = "";
    for (string numStr : numStrs) {
        answer += numStr;
    }
    
    return answer;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    answer = go(numbers);
    
    return answer;
}