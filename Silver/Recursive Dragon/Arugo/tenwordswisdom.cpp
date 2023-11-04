#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    int x = 0, q = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a <= 10 && b > q) {
            q = b;
            x = i;
        }
    }
    cout << x << "\n";
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