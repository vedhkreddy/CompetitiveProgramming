#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> query(int x) {
    cout << "? " << x + 1 << endl;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<int, int>> ans;
    auto solve = [&](auto self, int u, auto v, auto d) {
        if (v.size() == 1) {
            return;
        }
        int y = -1;
        for (auto x : v) {
            if (d[x] == 2) {
                y = x;
                break;
            }
        }
        if (y == -1) {
            for (auto x : v) {
                if (x == u) {
                    continue;
                }
                ans.emplace_back(u, x);
            }
            return;
        }
        auto dy = query(y);
        int mid = -1;
        vector<int> dmid, vmid, vu, vy;
        for (auto x : v) {
            if (dy[x] > d[x]) {
                vu.push_back(x);
            } else if (dy[x] < d[x]) {
                vy.push_back(x);
            } else {
                vmid.push_back(x);
                if (d[x] == 1) {
                    mid = x;
                }
            }
        }
        ans.emplace_back(u, mid);
        ans.emplace_back(y, mid);
        self(self, u, vu, d);
        self(self, y, vy, dy);
        for (auto &x : d) {
            x--;
        }
        self(self, mid, vmid, d);
    };
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    solve(solve, 0, v, query(0));
    cout << "!" << endl;
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << endl;
    }
    return 0;
}