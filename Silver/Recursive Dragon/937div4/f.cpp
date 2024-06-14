#include <iostream>
using namespace std;

void solve() {
    int i, j, k;
    cin >> i >> j >> k;
    
    int kk = 2, h = 0;
    
    if (i + 1 != k) {
        cout << -1 << endl;
        return;
    }
    
    if (j == 0) {
        kk = 1;
        while (kk - 1 < i) {
            kk *= 2;
            ++h;
        }
        cout << h << endl;
        return;
    }
    
    while (kk - 1 <= i) {
        kk *= 2;
        ++h;
    }

    cout << h + (j - kk + i + 2 * k) / k << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
