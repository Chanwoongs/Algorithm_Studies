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
			// ���ڰ� ������ ���� ���� * 10�� �ѵ� ����
			if (c >= '0' && c <= '9') x = x * 10 + (c - '0');
			// �ƴ� ��� deque�� ����
			else
			{
				if (x > 0) D.push_back(x);
				x = 0;
			}
		}
		if (x > 0) D.push_back(x);

		// �ʱⰪ (�������� ���� ����)
		bool error = false, rev = false;
		for (char let : P)
		{
			if (let == 'R') rev = !rev;
			else
			{
				// ��� �ִµ� �����Ϸ� �Ѵ�.
				if (D.empty())
				{
					error = true;
					break;
				}
				if (rev) D.pop_back();
				else D.pop_front();
			}
		}
		// ������ �߻��� ���
		if (error) cout << "error" << '\n';
		// �ƴ� ��� �ϳ��ϳ� ���� ���
		else
		{
			cout << '[';
			// ������ ���¸� ��¥ �����´�
			if (rev) reverse(D.begin(), D.end());
			for (int i = 0; i < D.size(); i++)
			{
				cout << D[i];
				// �Ǹ����� ���� ���� ��� �� �ڿ� ',' �־� �ֱ�
				if (i < D.size() - 1) cout << ',';
			}
			cout << "]\n";
		}
	}
}