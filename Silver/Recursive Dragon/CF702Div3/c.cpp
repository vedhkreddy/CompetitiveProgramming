#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e6 + 10;
int main () {
    vector<long long> p3(M, 0);
    for (int i = 0; i < M; i++) p3[i] = 1ll * i * i * i;
    unordered_set<long long> s(p3.begin(), p3.end());
 
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
 
        int can = 0;
        for (int i = 1; i < M && p3[i] < x && !can; i++)
            can |= s.count(x - p3[i]);
 
        cout << (can ? "YES\n" : "NO\n");
    }
}