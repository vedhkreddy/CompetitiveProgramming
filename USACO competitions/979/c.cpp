#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;
        string binaryString;
        cin >> binaryString;

        vector<int> positions(n, 0); // Initialize all positions as 0
        for (int i = 0; i < n; ++i) {
            if (binaryString[i] == '1') {
                positions[i] = 1;
            }
        }

        bool foundWinCondition = (positions[0] == 1 || positions[n - 1] == 1);
        
        for (int i = 1; i < n && !foundWinCondition; ++i) {
            if (positions[i] == 1 && positions[i - 1] == 1) {
                foundWinCondition = true;
            }
        }

        if (foundWinCondition) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
