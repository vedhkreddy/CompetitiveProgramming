#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int a[N];
pair <int, int> cost[N];
 
bool valid(int num, int n, int c) {
    ll sum = 0;
    ll ans = INF;
 
    for (int i = 1; i <= num; ++i) sum += cost[i].first;
    for (int i = 1; i <= num; ++i) {
        int x = cost[i].second;
        ans = min(ans, sum - cost[i].first + a[x] + x);
    }
    sum -= cost[num].first;
    
    for (int i = num + 1; i <= n; ++i) {
        int x = cost[i].second;
        ans = min(ans, sum + a[x] + x);
    }
 
    return ans <= c;
}
void solve() {
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i];
 
    for (int i = 1; i <= n; ++i) {
        cost[i].first = min(a[i] + i, a[i] + n - i + 1);
        cost[i].second = i;
    }
 
    sort(cost + 1, cost + n + 1);
    int L = 1, R = n, X = 0;
    while (L <= R) {
        int MID = L + R >> 1;
        
        if (valid(MID, n, c)) {
            X = MID; L = MID + 1;
        } else R = MID - 1;
    }
 
    cout << X << '\n';
}
int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}