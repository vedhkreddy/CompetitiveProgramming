#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long

int n, m;
vector<int> atks, defs; multiset<int> cls;
int def(multiset<int> cds){
  int c = 0;
  for(auto d : defs){
	auto it = cds.upper_bound(d);
	if(it == cds.end()) return -1;
	cds.erase(it);
  }

  for(auto a : atks){
	auto it = cds.lower_bound(a);
	if(it == cds.end()) return -1;
	c += *it-a; cds.erase(it);
  }

  for(auto cd : cds) c += cd;

  return c;
}

int atk(multiset<int> cds){
  int c = 0;
  for(auto a : atks){
	if(cds.size() < 1) break;
	auto it = --cds.end();
	if(*it < a) break;
	c += *it-a; cds.erase(it);
  }

  return c;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
	string s; cin >> s; int r; cin >> r;
	if(s == "ATK"){
	  atks.push_back(r);
	} else {
	  defs.push_back(r);
	}
  }
  for(int i = 0; i < m; i++) { int x; cin >> x; cls.insert(x); }
  sort(atks.begin(), atks.end());
  cout << max(def(cls), atk(cls)) << '\n';
  
  return 0;
}
