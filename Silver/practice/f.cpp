#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> graph;
vector<int> used;
 
void dfs(int v) {
    used[v] = true;
    for (auto elem : graph[v])
        if (!used[elem]) dfs(elem);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maxn = 1e6 + 179;
    vector<int> sieve(maxn);
    iota(sieve.begin(), sieve.end(), 0);
    for (int i = 2; i * i < maxn; i++) {
        if (sieve[i] != i) continue;
        for (int j = i * i; j < maxn; j += i)
            if (sieve[j] == j) sieve[j] = i;
    }
    vector<int> last(maxn, (int) -1e9);
    vector<int> divs;
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int sz = 2 * n - 1;
        vector<int> vec(sz);
        for (int i = n - 1; i < 2 * n - 1; i++) cin >> vec[i];
        for (int i = 0; i < n - 1; i++) vec[i] = vec[i + n];
        graph.assign(sz, {});
        used.assign(sz, 0);
        for (int i = 0; i < sz; i++) {
            int x = vec[i];
            divs.clear();
            while (x != 1) {
                divs.push_back(sieve[x]);
                x /= sieve[x];
            }
            divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
            for (auto elem: divs) {
                if (i - last[elem] <= k) {
                    graph[i].push_back(last[elem]);
                    graph[last[elem]].push_back(i);
                }
                last[elem] = i;
            }
        }
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            if (!used[i]) {
                ans++;
                dfs(i);
            }
        }
        for (int i = 0; i < sz; i++)
            if (vec[i] == 1) {
                if (i < n) ans += i;
                else ans += 2 * n - 2 - i;
            }
        cout << ans << '\n';
        for (int i = 0; i < sz; i++) {
            int x = vec[i];
            while (x != 1) {
                last[sieve[x]] = -1e9;
                x /= sieve[x];
            }
        }
    }
}