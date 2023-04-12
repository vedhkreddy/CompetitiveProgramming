#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
#define pb push_back
const int N = 300005;
 
int z, n, m, i, tab[N], res[N], lew[N];
set<ii> s;
char t[2];
VI v0, v1;
 
void go(VI& v) {
	set<ii>::iterator it, it2;
	s.clear();
	for (auto& w : v) {
		if (lew[w] && s.size() == 0) s.insert(ii(-tab[w], w)); else if (lew[w]) {
			it = s.end();
			it--;
			res[w] = res[it->second] = (tab[w] - it->first) / 2;
			s.erase(it);
		} else s.insert(ii(tab[w], w));
	}
	while (s.size() >= 2) {
		it = s.end();
		it--;
		it2 = it;
		it2--;
		res[it2->second] = res[it->second] = m - it->first + (it->first - it2->first) / 2;
		s.erase(it);
		s.erase(it2);
	}
}
 
bool cmp(int a, int b) {
	return tab[a] < tab[b];
}
 
 
int main() {
cin >> z;
while (z--) {
	cin >> n >> m;
	v0.clear();
	v1.clear();
	for (i=0;i<n;i++) {
		cin >> tab[i];
		if (tab[i] % 2) v1.pb(i); else v0.pb(i);
		res[i] = -1;
	}
	sort(v0.begin(), v0.end(), cmp);
	sort(v1.begin(), v1.end(), cmp);
	for (i=0;i<n;i++) {
		cin >> t;
		lew[i] = (t[0] == 'L');
	}
	go(v0);
	go(v1);
	for (i=0;i<n;i++) cout << res[i] << " ";
	cout << endl;
}
}