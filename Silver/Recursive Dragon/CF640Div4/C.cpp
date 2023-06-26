#include <bits/stdc++.h>
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll l = 0, r = 1e18;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll x = m - m / n;
            if (x < k) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << r << "\n";
    }
 
    return 0;
}
 