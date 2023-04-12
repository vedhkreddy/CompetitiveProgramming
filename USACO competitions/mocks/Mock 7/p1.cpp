#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int n;
int tot = 0;
int grid[5000][5000];
pii adj[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void addRemaining(int, int);

void add(int x, int y) {
  grid[x][y] = 0;
  for (pii p: adj) {
    int nextx = x + p.first;
    int nexty = y + p.second;
    if (grid[nextx][nexty] >= 0) {
      grid[nextx][nexty] ++;
      grid[x][y]++;
    }
  }
  
  if (grid[x][y] == 3)
    addRemaining(x,y);
  
  for (pii p: adj) {
    int nextx = x + p.first;
    int nexty = y + p.second;
    if (grid[nextx][nexty] == 3) {
        addRemaining(nextx, nexty);
    }
  }
      
}
void addRemaining(int x, int y) {
  tot++;
  for (pii p: adj) {
    int nextx = x + p.first;
    int nexty = y + p.second;
    if (grid[nextx][nexty] < 0)
      add(nextx, nexty);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < 5000; i++) {
    for (int j = 0; j < 5000; j++) {
      grid[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x += 2000;
    y += 2000;
    if (grid[x][y] >= 0)
      tot--;
    else
      add(x,y);
    cout << tot << endl;
  }
  return 0;
}