#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long k;
        cin >> k;

        long long left = 1, right = 2e18;

        while (right - left > 1) {
            long long mid = (left + right) / 2;
            long long n = mid - (long long)sqrtl(mid);

            if (n >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << right << "\n";
    }

    return 0;
}
