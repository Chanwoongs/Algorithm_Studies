#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
ll n, atk, t, a, h, H, mx, damage;

int main()
{
	cin >> n >> atk;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> a >> h;
		if (t == 1)
		{
			// 용사가 받을 total damage
			damage = a * (ceil((double)h / atk) - 1);
			if (H < damage)
			{
				mx += damage - H;
				H = 0;
			}
			else H -= damage;
		}
		else
		{
			atk += a;
			H = std::min((H + h), mx);
		}
	}
	cout << mx + 1 << '\n';
}