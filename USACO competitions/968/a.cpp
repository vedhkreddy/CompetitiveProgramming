#include <cstdio>

const int maxn = 110;

int n;
char s[maxn];

void solve() {
	scanf("%d%s", &n, s + 1);
	puts(s[1] != s[n] ? "Yes" : "No");
}

int main() {
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}