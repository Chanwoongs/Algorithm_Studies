#include <iostream>
#include <set>

using namespace std;

int n, m, a, res;
multiset<int> st;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        st.insert(a);
    }

    for (int i = 0; i < m; i++)
    {
        auto it1 = st.begin();
        auto val1 = *it1;
        auto it2 = next(st.begin());
        auto val2 = *it2;
        int sum = *it1 + *it2;

        st.erase(st.begin());
        st.erase(st.begin());

        st.insert(sum);
        st.insert(sum);
    }
    for (auto it : st)
    {
        res += it;
    }

    cout << res << '\n';
}