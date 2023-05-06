#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, m, tot;
vector<int> nods[N];
set<pair<int, int>> st1[N], st2[N];
vector<pair<int, int>> G[N * 2];
ll dis[N * 2];
bool inq[N * 2];
queue<int> Q;

void print(ll x) {
    if (x < 0) {
        putchar('-');
        print(-x);
        return;
    }
    if (x / 10)
        print(x / 10);
    putchar(x % 10 + 48);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1, c, r, d, s; i <= m; i++) {
        cin >> c >> r >> d >> s;
        st1[c].insert(make_pair(r, ++tot));
        st2[d].insert(make_pair(s, ++tot));
        G[tot - 1].emplace_back(tot, s - r);
        nods[c].emplace_back(tot - 1);
        nods[d].emplace_back(tot);
    }
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        for (auto j : st2[i]) {
            auto it = st1[i].lower_bound(make_pair(j.first + a, 0));
            if (it != st1[i].end()) {
                G[j.second].emplace_back(it->second, it->first - j.first);
            }
        }
        for (auto it = st1[i].begin(); it != st1[i].end(); it++) {
            if (next(it) != st1[i].end())
                G[it->second].emplace_back(next(it)->second, next(it)->first - it->first);
        }
        for (auto it = st2[i].begin(); it != st2[i].end(); it++) {
            if (next(it) != st2[i].end())
                G[it->second].emplace_back(next(it)->second, next(it)->first - it->first);
        }
    }
    memset(dis, 0x3f, sizeof dis);
    if (!st1[1].empty()) {
        G[++tot].emplace_back(st1[1].begin()->second, st1[1].begin()->first);
        Q.push(tot), dis[tot] = 0, inq[tot] = 1;
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        inq[x] = 0;
        for (auto y : G[x]) {
            if (dis[y.first] > dis[x] + y.second) {
                dis[y.first] = dis[x] + y.second;
                if (!inq[y.first])
                    Q.push(y.first), inq[y.first] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ll D = dis[0];
        for (int j : nods[i])
            D = min(D, dis[j]);
        if (i == 1)
            D = 0;
        if (D == dis[0])
            cout << -1 << '\n';
        else
            cout << D << '\n';
    }
    return 0;
}