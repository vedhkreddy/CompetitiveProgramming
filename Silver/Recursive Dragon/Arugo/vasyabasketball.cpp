#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
 
using namespace std;
 
int main(){
	vector<pair<int, bool> >meters;
	int n, m, current; cin >> n;
	for (int k = 0; k < n; k++){
		cin >> current;
		meters.push_back(make_pair(current, true));
	}
	cin >> m;
	for (int k = 0; k < m; k++){
		cin >> current;
		meters.push_back(make_pair(current, false));
	}
	sort(meters.begin(), meters.end(), greater<pair<int, bool> >());
	int totn = 2 * n, totm = 2 * m, maxsub = 2 * n - 2 * m, totmaxn = 2 * n;
	current = 0;
	int pointer = 0;
	while (pointer < n + m){
		current = meters[pointer].first;
		while (pointer < n + m && meters[pointer].first == current){
			if (meters[pointer].second)
				totn++;
			else
				totm++;
			pointer++;
		}
		if (totn - totm >= maxsub){
			maxsub = totn - totm;
			totmaxn = totn;
		}
	}
	cout << totmaxn << ':' << totmaxn - maxsub;
	return 0;
}