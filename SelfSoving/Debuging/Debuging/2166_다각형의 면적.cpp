#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double n, a, b, res;

int main()
{
	cin >> n;
	vector<pair<double, double>> v;

	for (int i = 0; i < n; i++) 
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	for (int i = 1; i < n - 1; i++) 
	{
		double a = v[0].first, b = v[0].second;
		double c = v[i].first, d = v[i].second;
		double e = v[i + 1].first, f = v[i + 1].second;

		res += (a * d + c * f + e * b - c * b - e * d - a * f) / 2.0;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(res) << endl;
}