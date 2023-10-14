#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    parent.resize(n + m + 1);

    for (int i = 1; i <= n + m; i++) {
        parent[i] = i;
    }

    int truthNum;
    cin >> truthNum;
    vector<int> truthPeople;

    while (truthNum--) {
        int x;
        cin >> x;
        truthPeople.push_back(x);
    }

    for (int i = n + 1; i <= n + m; i++) {
        int peopleNum;
        cin >> peopleNum;

        int firstPerson;
        if (peopleNum > 0) {
            cin >> firstPerson;
            merge(i, firstPerson);
        }

        for (int j = 1; j < peopleNum; j++) {
            int person;
            cin >> person;
            merge(firstPerson, person);
        }
    }

    int count = 0;
    for (int i = n + 1; i <= n + m; i++) {
        bool canLie = true;
        for (int truth : truthPeople) {
            if (find(truth) == find(i)) {
                canLie = false;
                break;
            }
        }
        if (canLie) count++;
    }

    cout << count << '\n';

    return 0;
}