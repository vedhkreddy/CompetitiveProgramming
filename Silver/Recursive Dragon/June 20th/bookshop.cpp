#include <iostream>
using namespace std;

const int maxN = 1000;
const int maxX = 1e5;

int main() {
    int N, X;
    int h[maxN], s[maxN], dp[maxX + 1];

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    fill(dp + 1, dp + X + 1, -1);
    for (int i = 0; i < N; i++) {
        for (int j = X - h[i]; j >= 0; j--) {
            if (dp[j] != -1) {
                dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
            }
        }
    }

    for (int i = 1; i <= X; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    
    cout << dp[X] << endl;

    return 0;
}
