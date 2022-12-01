#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long 
#define all(x) x.begin(), x.end()

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

const int N=100100;
int n, m, cnt;
vector<int> comp[N], adj[N], num(N);

void dfs(int u) {
	comp[cnt].push_back(u);
	num[u]=cnt;
	for(int v: adj[u]) if (num[v]==-1)
		dfs(v);
}

void calc(vector<ll> &f, int s) {
	int ori=num[s];
	for(int i=0; i<cnt; ++i)
		f[i]=1e15;
	f[ori]=0;
	for(int i=0; i<cnt; ++i) if (i^ori)
		for(ll j: comp[i]) {
			auto it=lower_bound(all(comp[ori]), j);
			if (it!=comp[ori].end()) umin(f[i], (j-*it)*(j-*it));
			if (it!=comp[ori].begin()) umin(f[i], (j-*--it)*(j-*it));
		}
}

void solve() {
	cin >> n >> m;

	cnt=0;
	for(int i=0; i<n; ++i)
		num[i]=-1, comp[i].clear(),	adj[i].clear();
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}

	for(int i=0; i<n; ++i) if (num[i]==-1)
		dfs(i), ++cnt;
	for(int i=0; i<cnt; ++i)
		sort(all(comp[i]));

	vector<ll> f(cnt), g(cnt);
	calc(f, 0);
	calc(g, n-1);

	ll best=f[num[n-1]];
	for(int i=0; i<n; ++i)
		umin(best, f[num[i]]+g[num[i]]);

	cout << best << '\n';
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++){
        solve();
    }
}
