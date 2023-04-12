#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
int v[N];
int s[N]; 
struct E {
	int to;
	E *nex;
} *h[N];
void add(int u, int v) {
	E *cur = new E;
	cur->to = v, cur->nex = h[u], h[u] = cur;
}
void dfs(int u) {
	s[u] = v[u] = 1;
	for (E *cur = h[u]; cur; cur = cur->nex)
		dfs(cur->to), s[u] += s[cur->to];
}
void get() {
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n + 1; i++)
		s[i] = v[i] = 0, h[i] = 0;
	for (i = 1; i <= n; i++) {
		cin >> a[i], a[i] = min(i + a[i], n + 1);
		if (a[i] <= 0) a[i] = n + 1;
		add(a[i], i);
	}
	dfs(n + 1); 
	long long ans = 0;
	if (v[1] == 1) {
		j = 1; do { ans -= s[j] + (n - s[n + 1] + 1), j = a[j]; }
		while (j != n + 1);
		ans += 1ll * n * (2 * n + 1);
	} else {
		j = 1; do { ans += (n + s[n + 1]), v[j] = 2, j = a[j]; }
		while (v[j] != 2);
	}
	cout << ans << endl;
}
int main() {
	int T;
	cin >> T;
	while (T--) get();
	return 0;
}