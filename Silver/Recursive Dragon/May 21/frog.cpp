#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int numStones;
    cin >> numStones;

    vector<int> stoneHeight;
    stoneHeight.reserve(numStones);
    
    for (int i = 0; i < numStones; i++) {
        int height;
        cin >> height;
        stoneHeight.push_back(height);
    }

    vector<int> dp(numStones, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < numStones - 1; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(stoneHeight[i] - stoneHeight[i + 1]));

        if (i + 2 < numStones) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(stoneHeight[i] - stoneHeight[i + 2]));
        }
    }

    cout << dp[numStones - 1] << endl;

    return 0;
}
