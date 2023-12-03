#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 21;

bool compat[MAX_N][MAX_N];
int dp[1 << MAX_N];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> compat[i][j];
		}
	}
	dp[0] = 1;
	for (int s = 0; s < (1 << N); s++) {
		int pair_num = __builtin_popcount(s);
		for (int w = 0; w < N; w++) {
			if ((s & (1 << w)) || !compat[pair_num][w])
				continue;
			dp[s | (1 << w)] += dp[s];
			dp[s | (1 << w)] %= MOD;
		}
	}

   	cout << dp[(1 << N) - 1] << endl;
}