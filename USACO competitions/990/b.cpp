#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<char, int> m;
        vector<char> v;
        char charmax = 'a', charmin = 'z';
        int timesmax = -1, timesmin = INT_MAX;

        for (int i = 0; i < n; i++) {
            char a;
            cin >> a;
            v.push_back(a);
            if (m.find(a) == m.end()) {
                m[a] = 1;
            } else {
                m[a]++;
            }
        }

        for (auto &p : m) {
            char c = p.first;
            int count = p.second;

            if (count < timesmin || (count == timesmin && c < charmin)) {
                timesmin = count;
                charmin = c;
            }
            if (count > timesmax || (count == timesmax && c > charmax)) {
                timesmax = count;
                charmax = c;
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[i] == charmin) {
                v[i] = charmax;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << v[i];
        }
        cout << endl;
    }
}
