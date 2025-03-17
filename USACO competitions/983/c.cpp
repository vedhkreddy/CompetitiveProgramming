#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    bool hasMultipleTests = true;
    if (hasMultipleTests) cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int l = 0, ans = n - 2;
        for (int r = 2; r < n; r++) {
            while (r - l >= 2 && a[l] + a[l+1] <= a[r]) l++;
            ans = min(ans, n - (r - l + 1));
        }

        cout << ans << endl;
    }

    return 0;
}
