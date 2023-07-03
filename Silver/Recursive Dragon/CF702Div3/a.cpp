#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
 
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
            while (2 * x < y) x *= 2, res++; 
        }
        cout << res << endl;
    }
}
 