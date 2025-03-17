#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int arraySize;
        cin >> arraySize;
        vector<int> heights(arraySize);
        for (int i = 0; i < arraySize; i++) cin >> heights[i];
        
        int maxVisible = 0;
        for (int i = 0; i < arraySize; i++) {
            int currentVisible = 0;
            for (int j = i; j < arraySize; j++) {
                if (heights[j] <= heights[i]) {
                    currentVisible += 1;
                }
            }
            maxVisible = max(maxVisible, currentVisible);
        }
        cout << arraySize - maxVisible << "\n";
    }
    return 0;
}
