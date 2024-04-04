
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << i << " " << n - i - 1 << "\n";
        }
    } else if (k < n - 1) {
        cout << k << " " << n - 1 << "\n";
        cout << n - 1 - k << " " << "0\n";
        for (int i = 1; i < n / 2; i++) {
            if (i != k && i != n - k - 1) {
                cout << i << " " << n - i - 1 << "\n";
            }
        }
    } else if (n == 4) {
        cout << "-1\n";
    } else {
        cout << n - 2 << " " << n - 1 << "\n";
        cout << "1 " << 3 << "\n";
        cout << n - 4 << " " << "0\n";
        for (int i = 2; i < n / 2; i++) {
            if (i != 3) {
                cout << i << " " << n - i - 1 << "\n";
            }
        }
    }
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