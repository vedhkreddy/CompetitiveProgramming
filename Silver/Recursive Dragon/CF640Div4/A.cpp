#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a;
        int p = 1;
        while (n != 0) {
            if (n % 10 != 0) {
                a.push_back(p * (n % 10));
            }
            n /= 10;
            p *= 10;
        }
        cout << a.size() << endl;
        for (int x : a)
            cout << x << " ";
        cout << endl;
    }
 
    return 0;
}