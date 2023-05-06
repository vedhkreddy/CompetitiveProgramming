#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int cnt[n+1] = {};
		for(int i = 0; i < n-1; i++) {
			int x, y;
			cin >> x >> y;
			cnt[x]++, cnt[y]++;
		}
		if (cnt[k] <= 1) {
			cout << "Ayush" << endl;
		}
		else if (n % 2 == 0) {
			cout << "Ayush" << endl;
		}
		else {
			cout << "Ashish" << endl;
		}
	}
}