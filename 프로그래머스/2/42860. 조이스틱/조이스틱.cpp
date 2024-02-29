#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1; // 기본적으로 오른쪽으로만 이동하는 경우

    for (int i = 0; i < n; i++) 
    {
        // 알파벳 변경에 필요한 최소 조작 횟수
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 다음 문자가 A인 경우, 커서 이동 최소화
        int next = i + 1;
        while (next < n && name[next] == 'A')
            next++;

        move = min(move, i + n - next + min(i, n - next));
    }

    answer += move;
    return answer;
}