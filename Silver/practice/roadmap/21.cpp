#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<std::pair<int, int>> vpi;

const int mod = 1000000007;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int did = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            vpi ord;
            int cur = a[2 * n - 1] + a[i];
            int was = cur;
            multiset<int> q(a.begin(), a.end());

            for (int j = 0; j < n; j++) {
                auto it = prev(q.end());
                int mx = *it;
                q.erase(it);
                it = q.find(cur - mx);

                if (it == q.end()) break;

                ord.push_back({cur - mx, mx});
                cur = mx;
                q.erase(it);
            }

            if (ord.size() == n) {
                did = 1;

                cout << "YES\n";
                cout << was << "\n";

                for (auto x : ord) {
                    cout << x.first << " " << x.second << "\n";
                }
                break;
            }
        }

        if (did == 0) {
            cout << "NO\n";
        }
    }

    return 0;
}
