#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t; 
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }

        long long max_score = 0;
        for (long long i = 1; i <= n; i++) {
            long long size = n / 2 + (n % 2 == 1 && i % 2 == 1);
            max_score = max(max_score, a[i] + size);
        }

        cout << max_score << "\n";
    }

    return 0;
}
