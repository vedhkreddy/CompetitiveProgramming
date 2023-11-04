#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fib(int n) {
  static vector<ll> mem{1, 1};
  while (mem.size() <= n) mem.push_back(mem.back() + mem[mem.size() - 2]);
  return mem[n];
}
bool check(int n, ll x, ll y) {
  if (n == 0) return true;
  if (y > fib(n - 1)) y = fib(n + 1) + 1 - y;
  if (y > fib(n - 1)) return false;
  return check(n - 1, y, x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    cout << (check(n, x, y) ? "YES" : "NO") << endl;
  }
  return 0;
}