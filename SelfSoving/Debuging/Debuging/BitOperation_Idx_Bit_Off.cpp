#include <iostream>

using namespace std;

int main()
{
	// #1. idx ��° ��Ʈ ���� 
	int S = 18, idx = 1;

	S &= ~(1 << idx);
	cout << S << '\n';

	// #2. idx ��° ��Ʈ�� toggle
	S = 18, idx = 1;

	S ^= 1 << idx;
	cout << S << '\n';

	// #3. ������ �����ִ� ��Ʈ ã��
	S = 18, idx = 1;

	idx = (S & -S);
	cout << idx << '\n';

	// #4. ũ�Ⱑ n�� ������ ��� ��Ʈ�� �ѱ�
	int n = 4;

	cout << (1 << n) - 1 << '\n';

	// #5. Idx ��° ��Ʈ �ѱ�
	S = 18; idx = 0;
	
	S |= (1 << idx);
	cout << S << '\n';

	// #6. Idx ��° ��Ʈ Ȯ���ϱ�
	S = 18; idx = 3;
	
	if (S & (1 << idx)) cout << '1' << '\n';
	else cout << '0' << '\n';

	return 0;
}