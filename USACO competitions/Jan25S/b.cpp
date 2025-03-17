#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for (ll& i : a) {
            cin >> i;
            i %= m;
        }
        sort(a.begin(), a.end());

        vector<ll> b(2 * n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
            b[i + n] = a[i] + m;
        }

        vector<ll> p(2 * n);
        partial_sum(b.begin(), b.end(), p.begin());

        ll ans = 1e18;
        for (int i = 0; i < 2 * n; i++) {
            if (b[i] - m / 2 >= 0 && b[i] + (m - 1) / 2 < 2 * m) {
                auto l = lower_bound(b.begin(), b.end(), b[i] - m / 2) - b.begin();
                ll ls = (i == 0 ? 0 : p[i - 1]) - (l - 1 < 0 ? 0 : p[l - 1]);
                ll lc = i - l;

                auto u = upper_bound(b.begin(), b.end(), b[i] + (m - 1) / 2) - b.begin();
                ll us = p[u - 1] - p[i];
                ll uc = u - 1 - i;

                ll res = (lc * b[i] - ls) + (us - uc * b[i]);
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
}
