#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    bool hasMultipleTests = true;
    if (hasMultipleTests) cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << "1\n1\n";
            continue;
        }

        if (k == 1 || k == n) {
            cout << "-1\n";
            continue;
        }

        int p2 = k - k % 2;
        int p3 = k + 1 + k % 2;
        cout << "3\n1 " << p2 << " " << p3 << endl;
    }

    return 0;
}
