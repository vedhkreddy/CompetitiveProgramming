#include<bits/stdc++.h>
using namespace std;
 
const int N = 1000 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
 
int n, m;
char a[N][N];
int dp[N][N];
 
int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
 
void dfs(int x, int y)
{
	if (dp[x][y]) {
		return;
	}
	dp[x][y] = -1;
	int nx, ny;
	int ret = 0;
	char ch = a[x][y], nch;
	for(int i = 0; i < 4; ++ i) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (valid(nx, ny)) {
			nch = a[nx][ny];
			if (ch == 'D' && nch != 'I') continue;
			if (ch == 'I' && nch != 'M') continue;
			if (ch == 'M' && nch != 'A') continue;
			if (ch == 'A' && nch != 'D') continue;
			dfs(nx, ny);
			if (dp[nx][ny] < 0) {
				dp[x][y] = -2;
				return;
			}
			ret = max(ret, dp[nx][ny]);
		}
	}
	dp[x][y] = ret + 1;
}
 
void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; ++ i) {
		scanf("%s", a[i]);
	}
	
	int ret = 0;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < m; ++ j) {
			dfs(i, j);
			if (dp[i][j] == -2) {
				cout << "Poor Inna!" << endl;
				return;
			}
			if (a[i][j] == 'D') {
				ret = max(ret, dp[i][j] / 4);
			}
		}
	}
	if (ret == 0) {
		cout << "Poor Dima!" << endl;
		return;
	}
	cout << ret << endl;
}
 
int main()
{
	solve();
	return 0;
}