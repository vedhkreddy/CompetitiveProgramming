#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    string t(n, '?');
    
    int cnt[26] {};
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    
    int l = 0, r = n - 1;
    for (int c = 0; c < 26; c++) {
        while (cnt[c] >= 2) {
            cnt[c] -= 2;
            t[l++] = t[r--] = 'a' + c;
        }
        if (cnt[c] == 1) {
            cnt[c] -= 1;
            if (l == r) {
                t[l] = 'a' + c;
            } else {
                int x = c + 1;
                while (cnt[x] == 0) {
                    x++;
                }
                if (cnt[x] == r - l) {
                    while (cnt[x] >= 2) {
                        cnt[x] -= 2;
                        t[l++] = t[r--] = 'a' + x;
                    }
                    if (cnt[x] == 1) {
                        cnt[x] -= 1;
                        t[l++] = 'a' + x;
                    }
                    t[r] = 'a' + c;
                } else {
                    for (; x < 26; x++) {
                        while (cnt[x] > 0) {
                            cnt[x] -= 1;
                            t[l++] = 'a' + x;
                        }
                    }
                    t[r] = 'a' + c;
                }
            }
            break;
        }
    }
    
    cout << t << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}