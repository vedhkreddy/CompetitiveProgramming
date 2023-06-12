#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1'000'000'007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<int> coins(n);
	for (int &c: coins) cin >> c;
	sort(coins.begin(), coins.end());

	vector<int> dp(x + 1);
	dp[0] = 1;  

	for (int i = 1; i <= x; i++) {
		for (int c: coins) {
			if (c > i) break;
			dp[i] += dp[i-c];
			dp[i] %= P;
		}
	}

	cout << dp[x] << endl;

	return 0;
}
