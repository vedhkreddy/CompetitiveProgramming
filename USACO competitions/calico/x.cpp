#include <iostream>
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e6;
constexpr int P = 1000000007;

int dp[N + 1], flag[N + 1];

int main() {
    for (int i = 1; i <= N; ++i) {
        dp[i] = (2ll * dp[i - 2] + dp[i - 1]) % P;
        if (flag[i - 1] && flag[i - 2]) {
            dp[i] = (dp[i] + 1) % P;
        } else {
            flag[i] = 1;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << 4ll * dp[n] % P << "\n";
    }

    return 0;
}
