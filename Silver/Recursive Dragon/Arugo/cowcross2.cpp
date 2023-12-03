#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int dp[MAXN + 1][MAXN + 1];

int main() {
	ifstream cin("nocross.in");
	ofstream cout("nocross.out");
	int n;
	cin >> n;
	vector<int> id1(n + 1), id2(n + 1);
	for (int i = 1; i <= n; i++) { cin >> id1[i]; }
	for (int i = 1; i <= n; i++) { cin >> id2[i]; }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max({dp[i - 1][j], dp[i][j - 1],
			                dp[i - 1][j - 1] + (abs(id1[i] - id2[j]) <= 4)});
		}
	}
	cout << dp[n][n] << endl;
}
