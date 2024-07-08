#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    vector<int> d(4, 0);
    vector<deque<int>> p(4);

    cin >> n;
    cin >> s;
    t = s;

    if (n == 2 && s[0] != s[1]) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'N':
                d[0]++;
                p[0].push_back(i);
                break;
            case 'S':
                d[1]++;
                p[1].push_back(i);
                break;
            case 'W':
                d[2]++;
                p[2].push_back(i);
                break;
            case 'E':
                d[3]++;
                p[3].push_back(i);
                break;
        }
    }

    if ((d[0] + d[1]) % 2 != 0 || (d[2] + d[3]) % 2 != 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < 4; ++i) {
        while (d[i] >= 2) {
            d[i] -= 2;
            t[p[i].front()] = 'R';
            p[i].pop_front();
            t[p[i].front()] = 'H';
            p[i].pop_front();
        }
    }

    if (d[0] && d[1]) {
        t[p[0].front()] = 'R';
        p[0].pop_front();
        t[p[1].front()] = 'R';
        p[1].pop_front();
    }
    if (d[2] && d[3]) {
        t[p[2].front()] = 'H';
        p[2].pop_front();
        t[p[3].front()] = 'H';
        p[3].pop_front();
    }

    cout << t << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
