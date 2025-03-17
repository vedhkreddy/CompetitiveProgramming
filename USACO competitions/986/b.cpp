#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, b, c; cin >> n >> b >> c;
        if (b == 0) {
            if (c >= n) {
                cout << n << endl;
            } else if (c >= n - 2) {
                cout << n - 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            ll min = 0;
            if (c >= n)
                cout << n << endl;
            else
                cout << n - max(min, 1 + (n - c - 1) / b) << endl;
        }
    }
}
