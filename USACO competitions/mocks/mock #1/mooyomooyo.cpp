#include <iostream>
#include <fstream>
using namespace std;
int n, k;
int grid[100][10];
int visited[100][10];
int check(int x, int y, int a) {
	int count = 0;
	if (x < 0 || x >= n || y < 0 || y >= 10 || visited[x][y]) {
		return 0;
	}
	if (grid[x][y] == a) {
		visited[x][y] = true;
		count++;
		count += check(x - 1, y, a);
		count += check(x + 1, y, a);
		count += check(x, y - 1, a);
		count += check(x, y + 1, a);
	}
	return count;
}
void gravity() {
	for (int i = 0; i < 10; i++) {
		int next = n - 1;
		for (int j = n - 1; j >= 0; j--) {
			visited[j][i] = false;
			if (grid[j][i] != 0) {
				int temp = grid[j][i];
				grid[j][i] = 0;
				grid[next][i] = temp;
				next--;
			}
		}
	}
}
void clear(int x, int y, int a) {
	if (x < 0 || x >= n || y < 0 || y >= 10) {
		return;
	}
	if (grid[x][y] == a) {
		grid[x][y] = 0;
		clear(x - 1, y, a);
		clear(x + 1, y, a);
		clear(x, y - 1, a);
		clear(x, y + 1, a);
	}
}
int main() {
	ifstream cin("mooyomooyo.in");
	ofstream cout("mooyomooyo.out");
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			char x;
			cin >> x;
			grid[i][j] = x - '0';
		}
	}
	bool done = false;
	while (!done) {
		done = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (grid[i][j] != 0 && !visited[i][j] && check(i, j, grid[i][j]) >= k) {
					done = false;
					clear(i, j, grid[i][j]);
				}
			}
		}
		if (!done) {
			gravity();
		}
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < 10; b++) {
			cout << grid[a][b];
		}
		cout << "\n";
	}
}
