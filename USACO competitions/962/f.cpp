#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> calculateScoreAndOps(int cutoffValue, const vector<int>& initialArray, const vector<int>& decrementArray, int arrayLength) {
    ll totalOps = 0;
    ll totalScore = 0;

    for (int i = 0; i < arrayLength; i++) {
        ll initialValue = initialArray[i];
        ll decrementValue = decrementArray[i];

        if (cutoffValue > initialValue)
            continue;

        ll operations = (initialValue - cutoffValue) / decrementValue;
        totalScore += (operations + 1) * initialValue - decrementValue * operations * (operations + 1) / 2;
        totalOps += operations + 1;

        totalScore = min(totalScore, 2 * (ll)1e18);
    }
    return make_pair(totalScore, totalOps);
}

void solve() {
    int arrayLength, maxOperations;
    cin >> arrayLength >> maxOperations;

    vector<int> initialArray(arrayLength), decrementArray(arrayLength);
    for (int &value : initialArray) cin >> value;
    for (int &value : decrementArray) cin >> value;

    int low = 0, high = 1e9 + 5;

    while (low < high) {
        int mid = (low + high) / 2;
        calculateScoreAndOps(mid, initialArray, decrementArray, arrayLength).second <= maxOperations ? high = mid : low = mid + 1;
    }

    auto [finalScore, operationsUsed] = calculateScoreAndOps(low, initialArray, decrementArray, arrayLength);
    cout << finalScore + (maxOperations - operationsUsed) * max(low - 1, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCases;
    cin >> testCases;

    while (testCases--)
        solve();
}
