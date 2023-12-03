#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
typedef pair <int ,int> pii ; 
const int MAXN = 2e5 + 5; 
int t , n , m ,k ; 
 
int main (){
	cin >> t; 
	while (t--){
		cin >> n >> m >> k ; 
		int h = k ,v = n * m / 2 - k ; 
		if (n & 1){
			if (m / 2 <= h){
				h -= m / 2 ; 
				n-- ; 
			}
			else {
				cout << "NO\n" ; 
				continue ; 
			}
		}
		if (m & 1){
			if (n / 2 <= v){
				v -= n / 2 ; 
				m-- ; 
			}
			else {
				cout << "NO\n" ; 
				continue ;
			}
		}
		if ((v & 1) || (h & 1)){
			cout << "NO\n" ; 
		}
		else {
			cout << "YES\n" ; 
		}
	}
	return 0 ; 
}
 