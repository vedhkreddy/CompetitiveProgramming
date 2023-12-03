#include<bits/stdc++.h>
using namespace std;

long long int n, m;
vector<pair<long long int, long long int>> v;

bool f(long long int to_check){
	
	long long int put = 0, cur_pos = v[0].first;
	
	for(int i = 0; i < m; ){
		if(put == n){break;}
		if(cur_pos >= v[i].first && cur_pos <= v[i].second){
			cur_pos += to_check;
			put++;
		}
		else if(v[i].first >= cur_pos){
			cur_pos = v[i].first + to_check;
			put++;
		}
		else{
			i++;
		}
	}
	
	return (put == n);
}

int main(){
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		long long int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	long long int lo = 0, hi = 1e18;
	
	while (lo < hi) {
		long long int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	
	cout << lo;
}