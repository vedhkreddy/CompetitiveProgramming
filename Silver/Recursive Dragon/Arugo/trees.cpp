#include <bits/stdc++.h>
 
using namespace std;
#define all(a) (a).begin(), (a).end()
 
int main() {
	int n, a;
	cin >> n;
	vector<int> cnt(100003);
	for(int i = 0; i < n; i++) {
		int x = (i < n / 2 ? 1 + i : n - i);
		cin >> a;
		if (a >= x)
			cnt[a - x]++;
	}
	cout << n - *max_element(all(cnt)) << endl;
}