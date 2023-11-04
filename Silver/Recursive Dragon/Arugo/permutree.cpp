#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
vector<vector<ll>> g;
vector<ll> sz;
 
ll dfs(ll v) {
    sz[v] = 1;
    ll res = 0;
    for (auto to: g[v]) {
        res += dfs(to);
        sz[v] += sz[to];
    }
    ll n = sz[v];
    vector<char> can(n + 1, 0);
    can[0] = 1;
    for (auto to: g[v]) {
        ll k = sz[to];
        for (ll j = n - k; j >= 0; --j) {
            if (can[j])can[j + k] = 1;
        }
    }
    ll best = 0;
    for (ll j = 1; j < n; ++j) {
        if (can[j])best = max(best, j * (n - j - 1));
    }
    res += best;
    return res;
}
 
int main() {
    ll n;
    cin >> n;
    g.resize(n);
    sz.resize(n);
    for (ll i = 1; i < n; ++i) {
        ll p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    cout << dfs(0);
    return 0;
}   