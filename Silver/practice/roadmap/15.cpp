#include <iostream>
#include <set>

using namespace std;

int n, m, h, t;
multiset<int> prices;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> h;
        prices.insert(-h);
    }

    for (int i = 0; i < m; ++i) {
        cin >> t;

        auto it = prices.lower_bound(-t);

        if (it == prices.end()) {
            cout << "-1\n";
        } else {
            cout << -(*it) << "\n";
            prices.erase(it);
        }
    }

    return 0;
}
