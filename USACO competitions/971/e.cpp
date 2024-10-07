#include <iostream>
#include <cmath>

using namespace std;

long long getMinValue(int n, int k) {
    long long totalSum = (n * (2 * k + n - 1)) / 2;
    
    // We need to check two cases:
    // Case 1: i = n // 2
    // Case 2: i = (n + 1) // 2
    long long i1 = n / 2;
    long long i2 = (n + 1) / 2;
    
    // Compute prefix sums for i1 and i2
    long long prefixSum1 = (i1 * (2 * k + i1 - 1)) / 2;
    long long prefixSum2 = (i2 * (2 * k + i2 - 1)) / 2;
    
    // Compute the absolute differences
    long long absDiff1 = abs(2 * prefixSum1 - totalSum);
    long long absDiff2 = abs(2 * prefixSum2 - totalSum);
    
    // Return the minimum of the two computed absolute differences
    return min(absDiff1, absDiff2);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << getMinValue(n, k) << endl;
    }
    
    return 0;
}
