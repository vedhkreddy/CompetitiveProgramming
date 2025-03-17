#include <iostream>
using namespace std;

int main() {
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        bool f = false;
        for (int k = 0; k * 9 <= x; k++) {
            if (x + 1 - y == k * 9) {
                f = true;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
}
