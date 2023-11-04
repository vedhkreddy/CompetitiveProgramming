#include <bits/stdc++.h>
using namespace std;
 
 
char maze[1010][1010];
 
const string chars = "+-|^><vLRUD*";
const string roted = "+|->v^<UDRL*";
 
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int rev[] = {2, 3, 0, 1};
// RDLU
 
int n, m;
 
 
string access[12];
 
int normalizeChar(char c) {
		return find(chars.begin(), chars.end(), c) - chars.begin();
}
 
void initAccess() {
	access[0] = "1111";
	access[1] = "1010";
	access[2] = "0101";
	access[3] = "0001";
	access[4] = "1000";
	access[5] = "0010";
	access[6] = "0100";
	access[7] = "1101";
	access[8] = "0111";
	access[9] = "1110";
	access[10] = "1011";
	access[11] = "0000";
}
 
int D[1005][1005][4];
bool viz[1005][1005][4];
 
pair<int, int> nextCoord(int i, int j, int r, int d) {
	int newi = i + di[d];
	int newj = j + dj[d];
 
	if(newi > n || newj > m || newi <= 0 || newj <= 0)
		return {-1, -1};
 
	int stateij = normalizeChar(maze[i][j]);
	int stateninj = normalizeChar(maze[newi][newj]);
 
	for(int i = 0; i < r; ++i) {
		stateij = normalizeChar(roted[stateij]);
		stateninj = normalizeChar(roted[stateninj]);
	}
 
	if(access[stateij][d] == '1' && access[stateninj][rev[d]] == '1')
		return {newi, newj};
	return {-1, -1};
 
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);
 
	initAccess();
	cin >> n >> m;
 
	for(int i = 1; i <= n; ++i)
		cin >> maze[i] + 1;
 
	int si, sj, ei, ej;
	cin >> si >> sj >> ei >> ej;
 
	queue<vector<int>> Q;
	Q.push({si, sj, 0});
	viz[si][sj][0] = 1;
 
	while(!Q.empty()) {
		auto now = Q.front();
		int i = now[0], j = now[1], r = now[2];
		Q.pop();
 
		for(int d = 0; d < 4; ++d) {
			auto nxt = nextCoord(i, j, r, d);
			if(nxt.first == -1) continue;
 
			if(!viz[nxt.first][nxt.second][r]) {
				viz[nxt.first][nxt.second][r] = 1;
				D[nxt.first][nxt.second][r] =
					D[i][j][r] + 1;
				Q.push({nxt.first, nxt.second, r});
			}
		}
 
		int nr = (r + 1) % 4;
		if(!viz[i][j][nr]) {
			viz[i][j][nr] = 1;
			D[i][j][nr] = D[i][j][r] + 1;
			Q.push({i, j, nr});
		}
	}
 
	const int INF = 0x7fffffff;
 
	int best = INF;
	for(int d = 0; d < 4; ++d) {
		if(!viz[ei][ej][d]) continue;
		best = min(best, D[ei][ej][d]);
	}
	if(best == INF) best = -1;
	cout << best << '\n';
	return 0;
}