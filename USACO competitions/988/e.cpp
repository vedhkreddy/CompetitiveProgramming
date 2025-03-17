#include <bits/stdc++.h>
using namespace std;

int query(int left, int right, map<pair<int, int>, int> &cache) {
    if (cache.find({left, right}) == cache.end()) {
        cout << "? " << left + 1 << " " << right + 1 << endl;
        cin >> cache[{left, right}];
    }
    return cache[{left, right}];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<pair<int, int>, int> cache;
        int n;
        cin >> n;
        vector<char> res(n, '0');
        int last = query(0, n - 1, cache);
        if (last) {
            int z = 1;
            for (int i = n - 2; i > 0; --i) {
                int current = query(0, i, cache);
                if (current != last) {
                    res[i + 1] = '1';
                }
                last = current;
                if (last == 0) {
                    z = i + 1;
                    break;
                }
            }
            if (last) {
                res[1] = '1';
                res[0] = '0';
            } else {
                last = 1;
                for (int j = z - 2; j >= 0; --j) {
                    int current = query(j, z, cache);
                    if (current == last) {
                        res[j] = '1';
                    }
                    last = current;
                }
            }
            cout << "! ";
            for (char c : res) cout << c;
            cout << endl;
        } else {
            cout << "! IMPOSSIBLE" << endl;
        }
    }
}
