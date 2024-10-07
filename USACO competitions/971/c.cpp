#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        long long moves_x = 2 * ((x + k - 1) / k) - 1;
        long long moves_y = 2 * ((y + k - 1) / k);
        cout << max(moves_x, moves_y) << endl;
    }
    return 0;
}
