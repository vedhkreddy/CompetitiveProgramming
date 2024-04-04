#include <bits/stdc++.h>
using namespace std;
/*
    1. monotonic function (the function is solely increasing)
    2. any higher value will not work for a lower value (of lines)
    Method 1: binary search on the answer
        binsearch on list (using check function)
    check function: o(1) complexity
        if (c <= k):
            return n(n-1)/2 <= x
        if (c > k)
            return sum
*/

#include <iostream>

using namespace std;

long long ap(long long a, long long b) {
    return (b + a) * (abs(b - a) + 1) / 2;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long k, x;
        cin >> k >> x;

        long long t = 0, f = k * 2;

        while (f - t > 1) {
            long long m = (t + f) / 2;
            long long c;

            if (m <= k) {
                c = ap(1, m);
            } else {
                c = ap(1, k) + ap(k - 1, k * 2 - m);
            }

            if (c < x) {
                t = m;
            } else {
                f = m;
            }
        }

        if (t < k * 2 - 1) {
            t++;
        }

        cout << t << endl;
    }

    return 0;
}
