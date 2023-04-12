#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define ll long long
const ll mod = 998244353, inv = (mod + 1) / 2;
int n;
map<ll, ll> s;
ll tot, mul = 1, ts = 1;
inline void add(ll &x, ll y) { (x += y) >= mod && (x -= mod); }
int main() {
  cin >> n;
  while (n--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll x;
      cin >> x;
      add(s[x + tot], ts);
    } else if (op == 2) {
      ll x;
      cin >> x;
      tot += x;
    } else if (tot <= 2e5) {
      if (tot == 0)
        mul = mul * 2 % mod, ts = ts * inv % mod;
      else {
        for (ll i = tot + 2e5; i > tot; i--) add(s[i + tot], s[i]);
        tot *= 2;
      }
    }
  }
  ll res = 0;
  for (auto i : s)
    if (i.first > tot) add(res, i.second);
  res = res * mul % mod;
  cout << res;
  return 0;
}