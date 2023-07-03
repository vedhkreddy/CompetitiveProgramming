#include <bits/stdc++.h>
 
using namespace std;
 
int BASE = 1000000007;
int n;
vector<vector<int>> neighbours;
vector<long long> freq;
 
int dfs(int node, int parent = -1) {
    int subtree = 1;
    for (int child : neighbours[node]) {
        if (child != parent) subtree += dfs(child, node);
    }
    if (parent != -1) freq.push_back(subtree * (long long)(n - subtree));
    return subtree;
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        neighbours.clear();
        neighbours.resize(1 + n);
        freq.clear();
 
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }

        dfs(1);
        sort(freq.begin(), freq.end());
 
        int m; cin >> m;
        vector<int> primes(m);
        for (int &x : primes) cin >> x;
        while (m < n-1) {
            primes.push_back(1);
            m++;
        }
        sort(primes.begin(), primes.end());
 
        vector<long long> product(n-1, 1);
 
        for (int i = 0; i < m; ++i) {
            int index = min(i, n-2);
            product[index] *= primes[i];
            product[index] %= BASE;
        }
 
        long long ans = 0;
        for (int i = 0; i < n-1; ++i) {
            ans += freq[i] * product[i] % BASE;
            ans %= BASE;
        }
        cout << ans << endl;
    }
}