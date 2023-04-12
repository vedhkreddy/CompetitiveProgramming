#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
using namespace std;

const int MAX_N = 250;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];


int floodfill(int size, int r, int c, int color1, int color2) {
	if((r < 0 || r >= n || c < 0 || c >= n) || (grid[r][c] != color1 && grid[r][c] != color2) || visited[r][c]) {
		return size;
	}
	visited[r][c] = 1;

	size++;
	size = floodfill(size, r, c + 1, color1, color2);
	size = floodfill(size, r, c - 1, color1, color2);
	size = floodfill(size, r - 1, c, color1, color2);
	size = floodfill(size, r + 1, c, color1, color2);
	return size;
}

int main() {
	ifstream cin("multimoo.in");
    ofstream cout("multimoo.out");
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!visited[i][j]) {
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j])); 
			}
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(ans >= n*n/2) {
				cout << ans << '\n';
				return 0;
			}
			if(grid[i][j] != grid[i][j-1]) {
				memset(visited, 0, sizeof(visited));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j-1]));
			}
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(ans >= n*n/2) {
				cout << ans << '\n';
				return 0;
			}
			if(grid[i][j] != grid[i-1][j]) {
				memset(visited, 0, sizeof(visited));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i-1][j]));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
