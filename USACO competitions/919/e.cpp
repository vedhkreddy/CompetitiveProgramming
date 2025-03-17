#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;
    
    while (t--) {
        int n;  // Length of the string
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> sheep_positions;
        
        // Collect the positions of all the sheep ('*')
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                sheep_positions.push_back(i);
            }
        }
        
        int k = sheep_positions.size();
        if (k == 0) {
            // If there are no sheep, no moves are needed
            cout << 0 << endl;
            continue;
        }
        
        // Find the median sheep
        int median_idx = k / 2;
        int median_position = sheep_positions[median_idx];
        
        // Calculate the minimum moves
        long long moves = 0;
        for (int i = 0; i < k; ++i) {
            // Move sheep i to the correct position relative to the median
            moves += abs(sheep_positions[i] - (median_position - median_idx + i));
        }
        
        cout << moves << endl;
    }
    
    return 0;
}