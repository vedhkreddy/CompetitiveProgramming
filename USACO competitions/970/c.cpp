#include <iostream>
#include <cmath>
using namespace std;

int findMaxGoodArrayLength(long long l, long long r) {
    long long max_sum = r - l;
    
    long long k = (sqrt(1 + 8.0 * max_sum) - 1) / 2;
    return k + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        cout << findMaxGoodArrayLength(l, r) << endl;
    }
    return 0;
}
