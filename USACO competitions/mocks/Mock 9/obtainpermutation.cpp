#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			--a[i][j];	
		}
	}
	
	long long ans = 0;
	for (int j = 0; j < m; ++j) {
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			if (a[i][j] % m == j) {
				int pos = a[i][j] / m;
				if (pos < n) {
					++cnt[(i - pos + n) % n];
				}
			}
		}
		int cur = n - cnt[0];
		for (int i = 1; i < n; ++i) {
			cur = min(cur, n - cnt[i] + i);
		}
		ans += cur;
	}
	
	cout << ans << endl;
	
	return 0;
}