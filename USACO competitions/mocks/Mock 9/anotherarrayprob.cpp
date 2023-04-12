#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t mod = 1e9 + 7;


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    if (n == 2)
        cout << max({2 * abs(a[0] - a[1]), a[0] + a[1]});
    else if (n == 3)
        cout << max({3 * (abs(a[0] - a[1])), 3 * (abs(a[2] - a[1])), 3 * a[0], 3 * a[2], a[0] + a[1] + a[2]});
    else
    {
        int mx = 0;
        for (auto i : a)
            mx = max(i, mx);
        cout << n * mx;
    }
    cout<<'\n';
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
}