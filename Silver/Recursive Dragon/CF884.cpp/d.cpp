#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    cin >> n;
    
    int t = 1;
    while (n % t == 0) {
        t++;
    }
    
    for (int i = 0; i < n; i++) {
        cout << char('a' + i % t);
    }
    cout << "\n";
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