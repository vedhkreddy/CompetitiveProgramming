#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    multimap<pair<int, int>, int> mp;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        mp.insert({{x, y}, i});
    }

    vector<int> v(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i = mp.begin(); i != mp.end(); ++i) {
        int a, b, c;
        tie(a, b) = i->first;

        if (pq.empty() or pq.top().first >= a) {
            c = ++cnt;
        } else {
            c = pq.top().second;
            pq.pop();
        }

        pq.push({b, c});
        v[i->second] = c;
    }

    cout << cnt << endl;

    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}
