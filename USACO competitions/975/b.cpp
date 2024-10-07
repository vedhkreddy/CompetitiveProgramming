#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<ll> x(n + 1, 0);
        for (ll i = 1; i <= n; i++) cin >> x[i];

        map<ll, ll> mp;
        for (ll i = 1; i <= n - 1; i++) {
            mp[i * (n - i)] += (x[i + 1] - x[i] - 1);
        }
        for (ll i = 1; i <= n; i++) {
            mp[i * (n - i + 1) - 1]++;
        }

        while (q--) {
            ll x; cin >> x;
            cout << mp[x] << ' ';
        }
        cout << endl;
    }

    return 0;
}
