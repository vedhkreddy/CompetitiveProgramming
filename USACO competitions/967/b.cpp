#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
    int size;
    cin >> size;
    
    if (size % 2 == 0) {
        cout << -1 << '\n';
    } else {
        vector<int> sequence(size);
        iota(sequence.begin(), sequence.end(), 1);  // Fill with 1, 2, ..., size
        
        for (int i = 1; i < size; i += 2) {
            swap(sequence[i], sequence[i + 1]);  // Swap every consecutive pair
        }
        
        for (int i = 0; i < size; ++i) {
            cout << sequence[i] << (i + 1 == size ? '\n' : ' ');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        solve();
    }
    
    return 0;
}
