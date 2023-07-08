#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5050;
ll a[N], b[N];
int n;
ll ans = 0;
 
int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	ll S = 0;
	for (int i = 0; i < n; i++)
		S += a[i] * b[i];
	ans = S;
	for (int i = 0; i < n; i++) {
		ll cur = S;
		int l = i, r = i;
		while(l > 0 && r + 1 < n) {
			l--;
			r++;
			cur -= a[l] * b[l] + a[r] * b[r];
			cur += a[l] * b[r] + a[r] * b[l];
			ans = max(ans, cur);
		}
	}
	for (int i = 1; i < n; i++) {
		ll cur = S;
		int l = i, r = i - 1;
		while(l > 0 && r + 1 < n) {
			l--;
			r++;
			cur -= a[l] * b[l] + a[r] * b[r];
			cur += a[l] * b[r] + a[r] * b[l];
			ans = max(ans, cur);
		}
	}
	cout << ans;
}