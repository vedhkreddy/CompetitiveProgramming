#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int res = 0;
		set<pair<int, int>> s;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if ((i + j) == n){
					s.insert(make_pair(i, j));
				}
			}
		}
		cout << s.size() << endl;
	}
}
