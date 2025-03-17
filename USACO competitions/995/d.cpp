#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for (int &val : a) {
            cin >> val;
        }

        sort(a.begin(), a.end());

        auto calcLessThanX = [&](vector<int> &arr, int x) {
            int n = arr.size();
            int s = accumulate(arr.begin(), arr.end(), 0);
            int j = 0, res = 0;

            for (int i = n - 1; i >= 0; --i) {
                while (j < n && s - arr[i] - arr[j] >= x) {
                    ++j;
                }
                res += (n - j);
            }

            for (int i = 0; i < n; ++i) {
                if (s - arr[i] - arr[i] < x) {
                    --res;
                }
            }

            return res / 2;
        };

        cout << calcLessThanX(a, y + 1) - calcLessThanX(a, x) << endl;
    }

    return 0;
}
