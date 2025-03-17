#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Yes cout << "Yes\n"
#define No cout << "No\n"

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        freq[x]++;
    }

    for (int i = 1; i < n; i++) {
        if (freq[i] > 2) {
            freq[i + 1] += freq[i] - 2;
            freq[i] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] % 2 == 1) {
            No;
            return;
        }
    }

    Yes;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) solve();
    
    return 0;
}
