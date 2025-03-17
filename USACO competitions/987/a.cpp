#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            freq[h[i]]++;
        }

        int maxFrequency = 0;
        for (const auto& [height, count] : freq) {
            maxFrequency = max(maxFrequency, count);
        }

        int result = n - maxFrequency;

        cout << result << endl;
    }
}
