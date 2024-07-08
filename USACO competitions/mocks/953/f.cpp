#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
 
typedef long long ll;
#define endl "\n"
 
const ll mod = 1;
const ll INF = (ll)1e18;
 
set<pair<ll, ll>> bridges;
ll n;
vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> tin, low;
ll timer;
 
void dfs(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (ll to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.insert({min(v, to), max(v, to)});
        }
    }
}
 
vector<ll> comp;
 
ll dfs2(ll i, ll c) {
    ll ret = 1;
    comp[i] = c;
    visited[i] = true;
    for (ll u: adj[i]) {
        if (!visited[u] && !bridges.contains({min(i, u), max(i, u)})) {
            ret += dfs2(u, c);
        }
    }
    return ret;
}
 
vector<vector<ll>> treeAdj;
 
void build(ll i) {
    visited[i] = true;
    for (ll u: adj[i]) {
        if (!visited[u]) {
 
            if (comp[u] != comp[i]) {
                treeAdj[comp[u]].push_back(comp[i]);
                treeAdj[comp[i]].push_back(comp[u]);
            }
 
            build(u);
        }
    }
}
 
ll answer;
 
vector<ll> sz;
 
ll sub(ll i, ll p) {
    ll subtree = sz[i];
    for (ll u: treeAdj[i]) {
        if (u != p) {
            subtree += sub(u, i);
        }
    }
    ll curr = (subtree * (subtree - 1)) / 2;
    curr += ((n - subtree) * (n - subtree - 1)) / 2;
    answer = min(answer, curr);
    return subtree;
}
 
void solve() {
 
    ll m;
    cin >> n >> m;
 
    adj.clear();
    visited.clear();
    tin.clear();
    low.clear();
    adj.resize(n);
    visited.resize(n);
    tin.resize(n, -1);
    low.resize(n, -1);
    bridges.clear();
    timer = 0;
 
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
 
    if (bridges.empty()) {
        ll ans = (n * (n - 1)) / 2;
        cout << ans << endl;
        return;
    }
 
    visited.clear();
    visited.resize(n);
    comp.clear();
    comp.resize(n);
    ll c = 1;
    sz.clear();
    sz.push_back(0);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            sz.push_back(dfs2(i, c));
            c++;
        }
    }
    treeAdj.clear();
    treeAdj.resize(c);
    visited.clear();
    visited.resize(n);
    build(0);
    answer = 1e18;
    ll x = sub(1, 1);
    cout << answer << endl;
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll tc = 0; tc < t; tc++) {
        solve();
    }
}