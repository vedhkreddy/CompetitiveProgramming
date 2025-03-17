#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int rectangleCount;
        cin >> rectangleCount;
        int maxWidth = 0, maxHeight = 0;
        for (int i = 0; i < rectangleCount; i++) {
            int width, height;
            cin >> width >> height;
            maxWidth = max(maxWidth, width);
            maxHeight = max(maxHeight, height);
        }
        cout << 2 * (maxWidth + maxHeight) << "\n";
    }
    return 0;
}
