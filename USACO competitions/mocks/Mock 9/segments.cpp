#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> calc(vector<vector<int>> a) {
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = {a[i][0], i};
        r[i] = {a[i][1], i};
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector<vector<pair<int, int>>> suf(n);
    vector<pair<int, int>> curr;
    for (int i0 = n - 1; i0 >= 0; --i0) {
        int xr = r[i0].first;
        int i = r[i0].second;
        int xl = a[i][0];
        int c = a[i][2];
        if (curr.empty()) {
            curr.emplace_back(xl, c);
        } else if (curr.size() == 1) {
            if (curr[0].second == c) {
                curr[0].first = min(curr[0].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        } else {
            if (curr[0].second == c) {
                curr[0].first = min(curr[0].first, xl);
            } else if (curr[1].second == c) {
                curr[1].first = min(curr[1].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        }
        sort(curr.begin(), curr.end());
        if (curr.size() == 3) {
            curr.pop_back();
        }
        suf[i0] = curr;
    }
    vector<int> ans(n, 1e9);
    int j = 0;
    for (int i0 = 0; i0 < n; ++i0) {
        int xl = l[i0].first, i = l[i0].second;
        int xr = a[i][1], c = a[i][2];
        while (j < n && r[j].first < xl) {
            j++;
        }
        if (j < n) {
            vector<pair<int, int>> s = suf[j];
            if (s[0].second != c) {
                ans[i] = min(ans[i], max(0, s[0].first - xr));
            } else if (s.size() == 2) {
                ans[i] = min(ans[i], max(0, s[1].first - xr));
            }
        }
    }
    return ans;
}

const int K = 1e9 + 1;

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3)), b(n, vector<int>(3));
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            if (j == 2) {
                b[i][j] = a[i][j];
            } else {
                b[i][1 - j] = K - a[i][j];
            }
        }
    }
    vector<int> ans1 = calc(a), ans2 = calc(b);
    for (int i = 0; i < n; ++i) {
        cout << min(ans1[i], ans2[i]) << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        solve();
    }
}