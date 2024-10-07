#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        ll array_size, queries;
        cin >> array_size >> queries;

        vector<ll> array(array_size), prefix_sum(1);
        for (ll &element : array) {
            cin >> element;
            prefix_sum.push_back(prefix_sum.back() + element);
        }

        for (ll &element : array) {
            prefix_sum.push_back(prefix_sum.back() + element);
        }

        while (queries--) {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;

            ll cycle_start = left / array_size, cycle_end = right / array_size;
            left %= array_size;
            right %= array_size;

            cout << prefix_sum[array_size] * (cycle_end - cycle_start + 1) 
                 - (prefix_sum[cycle_start + left] - prefix_sum[cycle_start]) 
                 - (prefix_sum[cycle_end + array_size] - prefix_sum[cycle_end + right + 1]) 
                 << endl;
        }
    }

    return 0;
}
