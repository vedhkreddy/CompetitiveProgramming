
#include <bits/stdc++.h>
 
using ll = long long;
 
using namespace std;
 
int main() {
    ll q;
    cin >> q;
    while (q--) {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n);
        vector<ll> s(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        s[0] = a[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
        ll su = a[0];
        int f = 1;
        for (int i = 1; i < n; i++) {
            if (su + a[i] >= (i + 1) * c) {
                f = 1;
                su = s[i];
            }
            else f = 0;
        }
        if (f) cout << "Yes\n";
        else cout << "No\n";
    }
}