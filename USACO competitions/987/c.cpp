#include <iostream>
#include <vector>
using namespace std;

// Predefined solution for n=27 (hardcoded base pattern for odd n >= 27)
vector<int> predefined27 = {
    1, 3, 3, 4, 4, 5, 5, 6, 6, 1, 2, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 1, 2
};

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        // Handle cases where no solution is possible
        if (n % 2 == 1 && n <= 25) {
            cout << -1 << endl;
            continue;
        }

        vector<int> result(n);

        // For even n, construct the sequence as described
        if (n % 2 == 0) {
            int value = 1;
            for (int i = 0; i < n; i += 2) {
                result[i] = result[i + 1] = value++;
            }
        } else {
            // Start with the predefined solution for n=27
            for (int i = 0; i < 27; ++i) {
                result[i] = predefined27[i];
            }

            // Extend the sequence for n > 27
            int current_value = 14; // Start from 14 since predefined27 uses values up to 13
            for (int i = 27; i < n; i += 2) {
                result[i] = result[i + 1] = current_value++;
            }
        }

        // Output the result
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
