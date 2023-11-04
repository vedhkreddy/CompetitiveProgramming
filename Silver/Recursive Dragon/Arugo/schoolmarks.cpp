#include <bits/stdc++.h>
using namespace std;
 
int main() { ios_base::sync_with_stdio(false);
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	
	vector<int> v;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a >= y) v.push_back(a);
		else v2.push_back(a);
	}
	
	int s = v.size();
	for (int i = 0; i < n / 2 + 1 - s; i++) {
		v.push_back(y);
		v3.push_back(y);
	}
	
	for (int i = 0; i < v2.size(); i++) {
		v.push_back(v2[i]);
	}
	
	s = n - v.size();
	for (int i = 0; i < s; i++) {
		v.push_back(1);
		v3.push_back(1);
	}
	
	int total = accumulate(v.begin(), v.end(), 0);
	
	if (v.size() > n || total > x) cout << -1;
	else
		for (auto e: v3) cout << e << ' ';
	return 0;
}