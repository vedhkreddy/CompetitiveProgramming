
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MOD = (int)1e9 + 7;
 
void add(int &x, int a) {
    x += a;
    if (x > MOD) {
        x -= MOD;
    }
}
 
int dp[2][4];
 
int main() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int p = i & 1;
        for (int j = 0; j < 4; j++) {
            dp[p ^ 1][j] = 0;
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    add(dp[p ^ 1][j], dp[p][k]);
                }
            }
        }
    }
    cout << dp[n & 1][0] << endl;
    return 0;
}