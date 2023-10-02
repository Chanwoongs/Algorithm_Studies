#include <iostream>

using namespace std;

int main()
{
	// #1. idx 번째 비트 끄기 
	int S = 18, idx = 1;

	S &= ~(1 << idx);
	cout << S << '\n';

	// #2. idx 번째 비트값 toggle
	S = 18, idx = 1;

	S ^= 1 << idx;
	cout << S << '\n';

	// #3. 최하위 켜져있는 비트 찾기
	S = 18, idx = 1;

	idx = (S & -S);
	cout << idx << '\n';

	// #4. 크기가 n인 집합의 모든 비트를 켜기
	int n = 4;

	cout << (1 << n) - 1 << '\n';

	// #5. Idx 번째 비트 켜기
	S = 18; idx = 0;
	
	S |= (1 << idx);
	cout << S << '\n';

	// #6. Idx 번째 비트 확인하기
	S = 18; idx = 3;
	
	if (S & (1 << idx)) cout << '1' << '\n';
	else cout << '0' << '\n';

	return 0;
}