#include<iostream>

using namespace std;

int main() 
{
	int t;
	cin >> t;


	for (int i = 0; i < t; i++) 
    {
		int n, m;
		cin >> n >> m;

		long answer = 1;
		int k = 1;
		for (int j = m; j > m - n; j--) {
			answer *= j;
			answer /= k;
			k++;
		}

		cout << answer << "\n";
	}
	return 0;
}