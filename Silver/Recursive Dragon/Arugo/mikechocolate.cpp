#include<bits/stdc++.h>
using namespace std;
 
 
long long calc(long long n) {
	long long res = 0;
	for (long long k = 2; k*k*k <= n;k++) {
		res += n / (k*k*k);
	}
	return res;
}
 
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long m;
	cin >> m;
	long long l = 0, r = m * 8;
	while (r-l>1) {
		long long mid = (l + r) / 2;
		if (calc(mid) >= m)r = mid;
		else l = mid;
	}
	if(calc(r)==m)cout << r << endl;
	else cout << -1 << endl;
	return 0;
}
