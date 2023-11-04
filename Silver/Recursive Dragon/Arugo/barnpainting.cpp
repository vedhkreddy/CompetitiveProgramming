#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;
const int mxN = 1e5;

int N, K, col[mxN];
ll dp[mxN][3];
bool vis[mxN];
vi adj[mxN], child[mxN];

void dfs(int u) {
	for(auto v : adj[u]) {
		if(!vis[v]) {
			vis[v] = true;
			child[u].pb(v);
			dfs(v);
		}
	}
	for(int paint1 = 0; paint1 < 3; ++paint1) {
		if(col[u] != -1 && col[u] != paint1) continue;
		dp[u][paint1] = 1;
		for(auto v : child[u]) {
			int sum = 0;
			for(int paint2 = 0; paint2 < 3; ++paint2) {
				if(paint1 == paint2) continue;
				(sum += dp[v][paint2]) %= MOD;
			}
			(dp[u][paint1] *= sum) %= MOD;
		}
	}
}

int main() { 
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ifstream cin ("barnpainting.in");
	ofstream cout ("barnpainting.out");

	memset(col, -1, sizeof(col));

	cin >> N >> K;

	for(int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	while(K--) {
		int u, x;
		cin >> u >> x, --u, --x;
		col[u] = x;
	}

	vis[0] = true;
	dfs(0);

	int ans = 0;

	for(int paint = 0; paint < 3; ++paint)
		(ans += dp[0][paint]) %= MOD;

	cout << ans << '\n';

	return 0;
}