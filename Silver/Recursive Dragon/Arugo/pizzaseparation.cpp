#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int solve = 100000000;
	
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += a[(i + j) % n];
			int rem = 360 - sum;
			int dif = abs(sum - rem);
			solve = min(solve,dif);
		}
	}
	
	cout << solve << endl;
 
	return 0;
}
