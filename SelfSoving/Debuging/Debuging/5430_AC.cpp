#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int T, N, x;
string P, order;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		deque<int> D;
		cin >> P >> N >> order;
		x = 0;
		for (char c : order)
		{
			if (c == '[' || c == ']') continue;
			// 숫자가 나오면 현재 수에 * 10을 한뒤 더함
			if (c >= '0' && c <= '9') x = x * 10 + (c - '0');
			// 아닐 경우 deque에 넣음
			else
			{
				if (x > 0) D.push_back(x);
				x = 0;
			}
		}
		if (x > 0) D.push_back(x);

		// 초기값 (뒤집히지 않은 상태)
		bool error = false, rev = false;
		for (char let : P)
		{
			if (let == 'R') rev = !rev;
			else
			{
				// 비어 있는데 제거하려 한다.
				if (D.empty())
				{
					error = true;
					break;
				}
				if (rev) D.pop_back();
				else D.pop_front();
			}
		}
		// 에러가 발생한 경우
		if (error) cout << "error" << '\n';
		// 아닐 경우 하나하나 원소 출력
		else
		{
			cout << '[';
			// 뒤집힌 상태면 진짜 뒤집는다
			if (rev) reverse(D.begin(), D.end());
			for (int i = 0; i < D.size(); i++)
			{
				cout << D[i];
				// 맨마지막 원소 빼고 출력 한 뒤에 ',' 넣어 주기
				if (i < D.size() - 1) cout << ',';
			}
			cout << "]\n";
		}
	}
}