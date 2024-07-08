#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
 
const int N = 2e5+1;
 
void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (n == 2) {
		cout << stoi(s) << endl;
		return;
	}
	if (n == 3) {
		cout << min({
			((s[0]-'0')*10+(s[1]-'0')) * (s[2]-'0'),
			(s[0]-'0') + (s[1]-'0')*10 + (s[2]-'0'),
			(s[0]-'0')*10+(s[1]-'0') + (s[2]-'0'),
			(s[0]-'0') * ((s[1]-'0')*10 + (s[2]-'0'))
		}) << endl;
		return;
	}
	for (int c : s) if (c == '0') {
		cout << "0" << endl;
		return;
	}
	for(char &c : s) c-='0';
	int ans = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		vector<int> d;
		
		for (int j = 0; j < n; j++) {
			if (j == i) {
				d.push_back(s[j] * 10 + s[j+1]);
				j++;
				continue;
			}
			d.push_back(s[j]);
		}
		int sum = 0;
		for (int x : d) {
			if (x == 1) continue;
			sum += x;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}
 
int main(){
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}