#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 110000;
int a[maxN], b[maxN];
 
int main() {
	int T;
	for (cin >> T; T; T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int t = -1; bool ok = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[i] == 0) continue;
			int g = __gcd(a[i], b[i]);
			a[i] /= g, b[i] /= g;
			int nn = a[i] % 2 * 2 + b[i] % 2;
			if (t == -1) t = nn;
			if (t != nn) ok = 0;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}