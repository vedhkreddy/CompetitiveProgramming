#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        string a, b;
        cin >> a >> b;
        
        vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
        vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));
        
        // Calculate frequency prefix sums for both strings a and b
        for (int i = 0; i < n; ++i) {
            freq_a[i + 1] = freq_a[i];
            freq_b[i + 1] = freq_b[i];
            freq_a[i + 1][a[i] - 'a']++;
            freq_b[i + 1][b[i] - 'a']++;
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; // Convert to 0-based index
            r--;
            
            int operations = 0;
            // Compare the frequencies for the range [l, r]
            for (int i = 0; i < 26; ++i) {
                int count_a = freq_a[r + 1][i] - freq_a[l][i];
                int count_b = freq_b[r + 1][i] - freq_b[l][i];
                operations += abs(count_a - count_b);
            }
            
            cout << operations / 2 << endl; // Since each operation affects both strings
        }
    }
    
    return 0;
}
