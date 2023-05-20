#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100100
 
int t, n, a, b, da, db;
int dep[MAXN], maxdep[MAXN];
vector<int> g[MAXN];
int ind, md;
 
void dfs1(int c, int l, int d) {
	dep[c] = d;
	maxdep[c] = d;
	for (int i : g[c])
		if (i != l) {
			dfs1(i, c, d + 1);
			maxdep[c] = max(maxdep[c], maxdep[i]);
		}
}
 
int dfs2(int c, int l) {
 
	int cv = 0;
	vector<int> cd;
	for (int i : g[c]) {
		if (i == l) continue;
		cv = max(cv, dfs2(i, c));
		cd.push_back(maxdep[i] - dep[c]);
	}
 
	sort(cd.begin(), cd.end());
	reverse(cd.begin(), cd.end());
 
	int ov = 0;
	if (cd.size()) ov += cd[0];
	if (cd.size() > 1) ov += cd[1];
 
	return max(cv, ov);
 
}
 
int main() {
 
	scanf("%d", &t);
	while (t--) {
		cin >> n >> a >> b >> da >> db;
		for (int i = 1; i <= n; i++)
			g[i].clear();
 
		for (int i = 1; i < n; i++) {
			int n1; int n2;
            cin >> n1 >> n2;
			g[n1].push_back(n2);
			g[n2].push_back(n1);
		}
 
		dfs1(a, -1, 0);
 
		if (dep[b] <= da || da >= db) {
			cout << "Alice" << endl;
			continue;
		}
 
		int diam = dfs2(a, -1);
		if (da >= (diam + 1) / 2) {
			cout << "Alice" << endl;
			continue;
		}
 
		if (db >= da * 2 + 1)
			cout << "Bob" << endl;
		else
			cout << "Alice" << endl;
 
	}
 
}