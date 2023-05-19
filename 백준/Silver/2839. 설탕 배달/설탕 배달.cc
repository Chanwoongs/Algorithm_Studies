#include <iostream>

using namespace std;

int main() 
{
    int N;
	cin >> N;
	int ans = 0;
	
	while (N>=0) 
	{
		if (N % 5 == 0) 
		{
			ans += (N / 5);	
			cout << ans << endl;
			return 0;
		}
		N -= 3;
		ans++;
	}
	cout << -1 << endl;
}