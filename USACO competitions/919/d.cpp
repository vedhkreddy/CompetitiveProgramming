#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, long long> freqMap;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        int key = a[i] - i;
        result += freqMap[key];
        freqMap[key]++; 
    }

    cout << result << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
