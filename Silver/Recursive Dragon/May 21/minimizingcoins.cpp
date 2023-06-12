#include <iostream>
#include <vector>

using namespace std;

const int MAX_X = 1e6;
const int INF = 1e9;

int main() {
    int N, X, c;
    cin >> N >> X;

    vector<int> dp(MAX_X + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> c;
        for (int j = 0; j <= X - c; j++) {
            if (dp[j] != INF) {
                dp[j + c] = min(dp[j + c], dp[j] + 1);
            }
        }
    }

    cout << (dp[X] == INF ? -1 : dp[X]) << endl;
}
