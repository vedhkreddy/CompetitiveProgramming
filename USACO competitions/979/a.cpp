#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; // input number of elements
        int mx = 0;
        int mn = 1000000;
        vector<int> lst(n); // list to store the input elements

        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
            mx = max(mx, lst[i]); // find max element
            mn = min(mn, lst[i]); // find min element
        }

        cout << (mx - mn) * (n - 1) << endl; // print the result
    }
    return 0;
}
