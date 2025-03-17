#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mn;
    for (int i = 0; i < n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++) {
            mn[i - j] = min(a[j], mn.count(i - j) ? mn[i - j] : 0);
        }
    }
    int ans = 0;
    for (const auto& value : mn) {
        ans -= value.second;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

