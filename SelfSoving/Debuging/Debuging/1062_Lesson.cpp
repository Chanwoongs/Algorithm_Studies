#include <iostream>
#include <string>
using namespace std;

int n, m, words[54];
string str;

int count(int mask)
{
	int cnt = 0;
	for (int word : words)
		if (word && (word & mask) == word) cnt++; // �ܾ�� ��� ���ڵ��� �����ؼ� ����� �ȹ����
	return cnt;
}

int go(int index, int k, int mask)
{
	if (k < 0) return 0;
	if (index == 26) return count(mask);

	// �ΰ����� �б�
	int res = go(index + 1, k - 1, mask | (1 << index)); // ���� ��
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
		res = max(res, go(index + 1, k, mask)); // ����� �ʴ� ��, antic �� ������ ������ ������Ѵ�.

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

// | �� ����� �� ������ �� 
// & �� ���� ��
// ^ �� ������ ��, ��� ���� ���� �ϰ�, ���� ����� �� (����)