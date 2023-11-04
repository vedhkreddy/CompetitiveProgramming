#include <stdio.h>
 
int n, k, a[100100], b[100100], frr;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		a[i] = k;
	}
	int q = 0, l = 0;
	for (int i = 0; i < n; ++i) {
		if (q == 0)
			if (a[i] == 1) {
				l = 1;
				q = 1;
			}
			else {
				l = 1;
				q = -1;
			}
		else if (q == 1) {
			if (a[i] != 1) {
				b[frr] = l;
				frr += 1;
				q = -1;
				l = 1;
			}
			else {
				l += 1;
			}
		}
		else {
			if (a[i] != 0) {
				b[frr] = l;
				frr += 1;
				q = 1;
				l = 1;
			}
			else {
				l += 1;
			}
		}
	}
	b[frr] = l;
	int i = 1;
	while (b[i] != 0) {
		if (b[i] != b[i - 1]) {
			printf("NO");
			return 0;
		}
		i += 1;
	}
	printf("YES");
	return 0;
}