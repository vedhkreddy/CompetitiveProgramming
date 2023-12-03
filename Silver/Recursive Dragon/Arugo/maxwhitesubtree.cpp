#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n, a[200000], ans[200000], dp[200000];
vector<int> adj[200000];
 
void dfs1(int u=0, int p=-1) {
	dp[u]=a[u];
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs1(v, u);
		dp[u] += max(dp[v], 0);
	}
}
 
void dfs2(int u = 0, int p  =-1, int pd = 0) {
	ans[u] = dp[u]+pd;
	for(int v : adj[u]) {
		if(v == p)
			continue;
		dfs2(v, u, max(ans[u]-max(dp[v], 0), 0));
	}
}
 
int main() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(!a[i])
			a[i]=-1;
	}
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	dfs2();
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
}