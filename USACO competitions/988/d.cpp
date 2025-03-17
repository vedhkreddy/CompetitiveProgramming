#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long L;
        cin >> n >> m >> L;

        vector<tuple<int, int, int>> events;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            events.emplace_back(a, b, 1); // Hurdle
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            events.emplace_back(a, b, 0); // Power-up
        }

        sort(events.begin(), events.end());

        int k = 1;
        priority_queue<int> powerups; // Max-heap for power-up values
        bool failed = false;

        for (auto &[a, b, t] : events) {
            if (t == 0) {
                powerups.push(b); // Add power-up
            } else {
                while (!powerups.empty() && k < b - a + 2) {
                    k += powerups.top();
                    powerups.pop();
                }
                if (k < b - a + 2) {
                    cout << -1 << endl;
                    failed = true;
                    break;
                }
            }
        }

        if (!failed) {
            cout << m - powerups.size() << endl;
        }
    }
}
