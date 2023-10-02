#include <iostream>
#include <string>
using namespace std;

int n, m, words[54];
string str;

int count(int mask)
{
	int cnt = 0;
	for (int word : words)
		if (word && (word & mask) == word) cnt++; // 단어랑 배운 글자들을 연산해서 배웠다 안배웠다
	return cnt;
}

int go(int index, int k, int mask)
{
	if (k < 0) return 0;
	if (index == 26) return count(mask);

	// 두갈래로 분기
	int res = go(index + 1, k - 1, mask | (1 << index)); // 배우는 것
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
		res = max(res, go(index + 1, k, mask)); // 배우지 않는 것, antic 는 위에서 무조건 배워야한다.

	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (char s : str)
			words[i] |= (1 << (s - 'a'));
	}
	cout << go(0, m, 0) << '\n';
}

// | 는 기록할 때 저장할 때 
// & 는 비교할 때
// ^ 는 스왑할 때, 재귀 돌때 연산 하고, 연산 취소할 때 (원복)