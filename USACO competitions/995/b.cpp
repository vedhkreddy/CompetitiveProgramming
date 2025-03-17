#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        int totalSum = a + b + c;
        int res = (n / totalSum) * 3;

        if (n % totalSum == 0) {
            cout << res << endl;
        } else if (n % totalSum <= a) {
            cout << res + 1 << endl;
        } else if (n % totalSum <= a + b) {
            cout << res + 2 << endl;
        } else {
            cout << res + 3 << endl;
        }
    }
}
