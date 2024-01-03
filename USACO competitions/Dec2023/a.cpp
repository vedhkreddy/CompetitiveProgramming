#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
ll n, x;
ll d[1000010], ds[1000010], s[1000010], ss[1000010];
 
ll calc (ll x) {return x * (x + 1) / 2;}
ll calc (ll a, ll b) {return (a + b) * (b - a + 1) / 2;}
 
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		cin >> d[i];
		ds[i] = ds[i - 1] + d[i];
		s[i] = calc(d[i]);
		ss[i] = s[i] + ss[i - 1];
	}
 
	ll fans = 0;
 
	int pt = n + 1, pt2 = n + 1;
	for (int i = n; i >= 1; i --) {
		while (pt > 1 && ds[i] - ds[pt - 2] <= x)
			pt --;
		if (pt == 1 && ds[i] - ds[pt - 1] < x) {
			ll left = x - (ds[i] - ds[pt - 1]);
			ll val1 = ss[i];
			while (pt2 > 1 && ds[n] - ds[pt2 - 2] <= left)
				pt2 --;
			ll val2 = ss[n] - ss[pt2 - 1];
			ll val3 = calc(d[pt2 - 1] - (left - (ds[n] - ds[pt2 - 1])) + 1, d[pt2 - 1]);
			fans = max (fans, val1 + val2 + val3);
		}
		else {
			ll val1 = ss[i] - ss[pt - 1];
			ll left = x - (ds[i] - ds[pt - 1]);
			ll val2 = calc(d[pt - 1] - left + 1, d[pt - 1]);
			fans = max(fans, val1 + val2);
		}
	}
    cout << fans << endl;
}