// 참고한 영상
// https://www.youtube.com/watch?v=sSno9rV8Rhg
#include <iostream>
using namespace std;

int LCS[100][100] = { 0, };
int result[100] = { 0 };

int main()
{
	string str1, str2;
	int idx = 0;

	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
				result[idx] = LCS[i][j];
				idx++;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	for (int i = 0; i < idx; i++)
	{
		cout << result[i];
	}

	cout << "Result : " << LCS[str1.length() - 1][str2.length() - 1];
}