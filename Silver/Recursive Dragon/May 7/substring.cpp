#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 3e5 + 50;
 
bool visited[maxN];
bool inRec[maxN];
bool cycle = false;
 
string s;
vector < int > G[maxN];
int DP[maxN];
 
void DFSCycle(int node) {
	visited[node] = true;
	inRec[node] = true;
 
	for(auto it: G[node]) {
		if(visited[it] == false) {
			DFSCycle(it);
		} else {
			if(inRec[it]) { 
				cout << -1;
				exit(0);
			}
		}
	}
	inRec[node] = false;
}
 
void HasCycles(int n, int m) {
	for(int i = 1; i <= n; ++i) {
		if(visited[i] == false) {
			DFSCycle(i);
		}
	}
}
 
char ch;
void DFS(int node) {
	visited[node] = true;
 
	int mx = 0;
	for(auto it: G[node]) {
		if(visited[it] == false) {
			DFS(it);
		}
		mx = max(DP[it], mx);
	}
	if(s[node] == ch) {
		DP[node] = mx + 1;
	} else {
		DP[node] = mx;
	}
}
 
int main() {
	int n, m;
	cin >> n >> m >> s;
 
	s = '$' + s;
 
	for(int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
 
		G[x].push_back(y);
	}
 
	HasCycles(n, m);
 
	int ans = 0;
	for(ch = 'a'; ch <= 'z'; ++ch) {
		for(int i = 1; i <= n; ++i) DP[i] = 0;
		for(int i = 1; i <= n; ++i) visited[i] = false;
 
		for(int i = 1; i <= n; ++i) {
			if(s[i] == ch && visited[i] == false) {
				DFS(i);
			}
			ans = max(ans, DP[i]);
		}
	}
 
	cout << ans;
}
