#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void dfs(int v, int par, int cuenta, vector<int> *g, char *milk, int *comp) {
    comp[v] = cuenta;
    for (int u : g[v]) {
        if (u!=par && milk[u]==milk[v]) {
            dfs(u, v, cuenta, g, milk, comp);
        }
    }
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    int n, m; cin >> n >> m;
    vector<int> g[n+1];
    char milk[n+1];
    for (int i=1; i<=n; i++) {
        cin >> milk[i];
    }
    for (int i=1; i<n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int comp[n+1];
    fill(comp, comp+n, 0);
    int cuenta = 0;
    for (int v=1; v<=n; v++) {
        if (comp[v]==0) {
            cuenta++;
            dfs(v, 0, cuenta, g, milk, comp);
        }
    }
    vector<bool> ans;
    while (m--) {
        int a, b; cin >> a >> b;
        char c; cin >> c;
        bool x = 1;
        if (comp[a]==comp[b] && milk[a]!=c) {
            x = 0;
        }
        ans.push_back(x);
    }
    for (bool x : ans) {
        cout << x;
    }
}