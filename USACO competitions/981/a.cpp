#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 0;
    int c = 1;

    while (-n <= x && x <= n) {
        if (c % 2 == 1) {
            x -= 2 * c - 1;
        } else {
            x += 2 * c - 1;
        }
        c++;
    }

    if (c % 2 == 0) {
        cout << "Sakurako" << endl;
    } else {
        cout << "Kosuke" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
