#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int get(int x, int k) {
    return (k - x % k) % k;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;

        int sum = 0, flag = 1;
        for (int i = 0; i < 26; ++i) {
            sum += get(cnt[i], k);
        }

        if (sum == 0) {
            cout << s << '\n';
            flag = 0;
        }

        if (n % k != 0) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = n - 1; i >= 0 && flag; --i) {
            sum -= get(cnt[s[i] - 'a'], k);
            cnt[s[i] - 'a']--;
            sum += get(cnt[s[i] - 'a'], k);
            for (int j = s[i] - 'a' + 1; j < 26; ++j) {

                int lst_sum = sum;
                sum -= get(cnt[j], k);
                cnt[j]++;
                sum += get(cnt[j], k);

                if (i + sum + 1 <= n) {
                    for (int pos = 0; pos < i; ++pos) {
                        cout << s[pos];
                    }
                    cout << char('a' + j);

                    string add = "";
                    for (int w = 0; w < 26; ++w) {
                        int f = get(cnt[w], k);
                        while (f) {
                            f--;
                            add += char('a' + w);
                        }
                    }
                    while ((int)add.size() + i + 1 < n) {
                        add += "a";
                    }

                    sort(add.begin(), add.end());
                    cout << add << '\n';
                    flag = 0;
                    break;
                }

                cnt[j]--;
                sum = lst_sum;
            }
        }
    }
    return 0;
}