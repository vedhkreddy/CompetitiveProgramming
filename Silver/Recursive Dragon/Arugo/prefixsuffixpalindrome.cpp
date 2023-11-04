#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()
 
typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

vector<int> nch(string s) {
    int n = len(s);
    vector<int> d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
            ++k;
        d1[i] = k;
        if (i + k - 1 > r)
            l = i - k + 1, r = i + k - 1;
    }
    return d1;
}

vector<int> ch(string s) {
    int n = len(s);
    vector<int> d2(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])
            ++k;
        d2[i] = k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    return d2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k = 0;
        for (int i = 0; i < len(s) / 2; i++) {
            if (s[i] == s[len(s) - 1 - i]) {
                k = i + 1;
            } else {
                break;
            }
        }
        int h = k;
        int mx = 0;
        string flex = s.substr(0, k);
        s.erase(0, k);
        while (k--) {
            s.pop_back();
        }
        vector<int> a = nch(s);
        for (int i = 0; i < len(a); i++) {
            if (i - a[i] + 1 == 0 || i + a[i] == len(a)) {
                mx = max(a[i] * 2 - 1, mx);
            }
        }
        vector<int> b = a;
        a = ch(s);
        for (int i = 0; i < len(a); i++) {
            if (i - a[i] == 0 || i + a[i] == len(a)) {
                mx = max(a[i] * 2, mx);
            }
        }
        if (mx % 2) {
            a = b;
            cout << flex;
            reverse(all(flex));
            for (int i = 0; i < len(a); i++) {
                if ((a[i] * 2 - 1 == mx) && (i - a[i] + 1 == 0 || i + a[i] == len(a))) {
                    for (int j = i - a[i] + 1; j < i + a[i]; j++) {
                        cout << s[j];
                    }
                    break;
                }
            }
            cout << flex;
        } else {
            cout << flex;
            reverse(all(flex));
            for (int i = 0; i < len(a); i++) {
                if (a[i] * 2 == mx && (i - a[i] == 0 || i + a[i] == len(a))) {
                    for (int j = i - a[i]; j < i + a[i]; j++)
                        cout << s[j];
                    break;
                }
            }
            cout << flex;
        }
        cout << endl;
    }

    return 0;
}
