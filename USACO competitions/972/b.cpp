#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    vector<int> t(y);
    for (int i = 0; i < y; i++) cin >> t[i];
    sort(t.begin(), t.end());

    while (z--) {
        int d;
        cin >> d;

        // Use upper_bound to find the first teacher to the right
        int k = upper_bound(t.begin(), t.end(), d) - t.begin();
        //cout << k << endl;
        // Case 1: No teacher to the left, return distance to the first teacher
        if (k == 0) {
            cout << t[0] - 1 << '\n';
        }
        // Case 2: No teacher to the right, return distance to the last teacher
        else if (k == y) {
            cout << x - t[y-1] << '\n';
        }
        // Case 3: Teachers exist on both sides, take the minimum distance
        else {
            int left_dist = d - t[k - 1];
            int right_dist = t[k] - d;
            cout << (t[k] - t[k-1])/2 << '\n';
        }
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}
