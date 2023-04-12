#include <iostream>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int n, k;
pii swaps[200001];
int swapped[100001];
int cycle[100001];
set<int> visited[100001];

int main() {
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    swapped[i] = i;
    cycle[i] = -1;
  }
  for (int i = 0; i < k; i++) {
    cin >> swaps[i].first >> swaps[i].second;
    int tmp = swapped[swaps[i].first];
    swapped[swaps[i].first] = swapped[swaps[i].second];
    swapped[swaps[i].second] = tmp;
  }

  int currcycle = 0;
  for (int i = 1; i <= n; i++) {
    if (cycle[i] != -1) {
      continue;
    }
    cycle[i] = currcycle;
    visited[currcycle].insert(i);
    int curr = swapped[i];
    while (curr != i) {
      cycle[curr] = currcycle;
      visited[currcycle].insert(curr);
      curr = swapped[curr];
    }
    currcycle++;
  }
  for (int i = 1; i <= n; i++) {
    swapped[i] = i;
  }
  for (int i = 0; i < k; i++) {
    visited[cycle[swapped[swaps[i].first]]].insert(swaps[i].second);
    visited[cycle[swapped[swaps[i].second]]].insert(swaps[i].first);

    int tmp = swapped[swaps[i].first];
    swapped[swaps[i].first] = swapped[swaps[i].second];
    swapped[swaps[i].second] = tmp;
  }

  for (int i = 1; i <= n; i++) {
    cout << visited[cycle[i]].size() << endl;
  }
}