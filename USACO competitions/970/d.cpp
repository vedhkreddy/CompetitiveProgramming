#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> F(n);
    vector<bool> visited(n, false);
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // zero-indexing the permutation
    }
    cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // Start a new cycle
            vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                j = p[j];
            }
            
            int black_count = 0;
            for (int idx : cycle) {
                if (s[idx] == '0') {
                    black_count++;
                }
            }
            
            for (int idx : cycle) {
                F[idx] = black_count;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
