#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101];
void solve() {
    int n;
    cin >> n;

    bool f = true;
    int in = n;
    while (in) {
        if (in % 10 > 1) f = false;
        in /= 10;
    }
    if (f) {
        cout << "YES\n";
        return;
    }

    int p = 0;
    while (a[p] <= n) {
        if (n % a[p] == 0) {
            n /= a[p];
        } else {
            ++p;
        }
    }
    cout << (n == 1 ? "YES" : "NO") << '\n';  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p = 0;
    for (int i = 10; i <= 50000; i++) {
        int k = i;
        bool f = true;
        while (k) {
            if (k % 10 > 1) f = false;
            k /= 10;
        }
        if (f) a[p++] = i;
    }
    a[p] = 111111;
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
