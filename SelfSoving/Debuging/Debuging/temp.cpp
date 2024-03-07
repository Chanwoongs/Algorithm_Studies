#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long amount;
    cin >> n >> k >> amount;
    vector<int> a(n), b(n);
    vector<pair<int, int>> diff(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        diff[i] = { b[i] - a[i], i };
    }

    sort(diff.rbegin(), diff.rend());

    for (int i = 0; i < k && i < n; ++i) {
        if (diff[i].first > 0) {
            amount += 5 * diff[i].first;
            a[diff[i].second] = b[diff[i].second];
        }
    }

    for (auto price : a) {
        if (price > amount) {
            cout << "Not enough money";
            return 0;
        }
        amount -= price;
    }

    cout << "Remaining money: " << amount;
    return 0;
}