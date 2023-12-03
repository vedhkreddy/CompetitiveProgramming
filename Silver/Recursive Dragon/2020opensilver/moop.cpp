#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("moop.in");
ofstream fout("moop.out");

int n;
pair<int,int> xy[100001];
vector<int> lowerbounds;

int main() {
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> xy[i].first >> xy[i].second;
  }
  sort(xy, xy + n);
  lowerbounds.push_back(xy[0].second);
  for (int i = 1; i < n; i++) {
    int y = xy[i].second;
    vector<int>::iterator itr = upper_bound(lowerbounds.begin(), lowerbounds.end(), y);
    if (itr == lowerbounds.begin()) {
      lowerbounds.insert(lowerbounds.begin(), y );
    }
    else {
      itr--;
      while (itr != lowerbounds.begin()) {
        lowerbounds.erase(itr--);
      }
    }
  }
  fout << lowerbounds.size() << endl;
}