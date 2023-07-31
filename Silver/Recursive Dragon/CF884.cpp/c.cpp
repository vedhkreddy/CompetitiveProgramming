#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    ll ans = -1E18;
    for (int t = 0; t < 2; t++) {
        ll sum = 0;
        int mx = -1E9;
        for (int i = t; i < n; i += 2) {
            if (c[i] > 0) {
                sum += c[i];
            }
            mx = max(mx, c[i]);
        }
        if (sum == 0) {
            sum = mx;
        }
        ans = max(ans, sum);
    }
    
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
