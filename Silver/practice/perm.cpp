#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define all(x) x.begin(), x.end()
int INFI = 1e9 + 7;
 
vector<pair<int, int> > seg;
vector<int> a;
 
void build(int id, int l, int r) {
    if (r - l == 1) {
    seg[id].first = a[l];
    seg[id].second = a[l];
    return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m, r);
    seg[id].first = min(seg[id * 2].first, seg[id * 2 + 1].first);
    seg[id].second = max(seg[id * 2].second, seg[id * 2 + 1].second);
    return;
}
 
pair<int, int> get(int id, int l, int r, int s_l, int s_r) {
    if (l >= s_r || s_l >= r) {
    return {INFI, -INFI};
    }
    if (s_l <= l && r <= s_r) {
    return seg[id];
    }
    int m = (l + r) / 2;
    auto first = get(id * 2, l, m, s_l, s_r);
    auto second = get(id * 2 + 1, m, r, s_l, s_r);
    return {min(first.first, second.first), max(first.second, second.second)};
}
 
vector<vector<int> > g;
 
void run() {
    int n;
    cin >> n;
    seg.clear();
    a.clear();
    seg.resize(4 * n);
    a.resize(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
    }
    stack<pair<int, int> > st;
    vector<int> right(n, n);
    for (int i = 0; i < n; i++) {
    if (st.size() == 0) {
        st.push({a[i], i});
    } else {
        while (st.size() > 0 && st.top().first > a[i]) {
        right[st.top().second] = i;
        st.pop();
        }
        st.push({a[i], i});
    }
    }
    while (st.size() > 0) {
    st.pop();
    }
    vector<int> left(n, n);
    for (int i = 0; i < n; i++) {
    if (st.size() == 0) {
        st.push({a[i], i});
    } else {
        while (st.size() > 0 && st.top().first < a[i]) {
        left[st.top().second] = i;
        st.pop();
        }
        st.push({a[i], i});
    }
    }
    g.clear();
    g.resize(n);
    build(1, 0, n);
    a.push_back(INFI);
    for (int i = 0; i < n; i++) {
    if (a[i + 1] > a[i]) {
        auto now = get(1, 0, n, i + 1, right[i]);
        g[i].push_back(mp[now.second]);
    } else {
        auto now = get(1, 0, n, i + 1, left[i]);
        g[i].push_back(mp[now.first]);
    }
    }
    vector<int> dist(n, INFI);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (auto u : g[v]) {
        if (dist[u] > dist[v] + 1) {
        dist[u] = dist[v] + 1;
        q.push(u);
        }
    }
    }
    cout << dist[n - 1] << endl;
    }


    signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        run();
    }


    return 0;
}