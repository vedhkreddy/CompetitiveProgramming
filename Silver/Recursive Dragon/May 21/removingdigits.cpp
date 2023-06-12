#include <iostream>
using namespace std;

const int maxN = 1e6;
const int INF = 0x3f3f3f3f;

int main() {
    int N, dp[maxN + 1];

    cin >> N;
    fill(dp + 1, dp + N + 1, INF);

    for (int i = 1; i <= N; i++) {
        int d = i;
        while (d > 0) {
            if (d % 10 != 0) {
                dp[i] = min(dp[i], dp[i - (d % 10)] + 1);
            }
            d /= 10;
        }
    }

    cout << dp[N] << endl;

    return 0;
}
