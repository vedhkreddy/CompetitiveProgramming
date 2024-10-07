#include <bits/stdc++.h>
using namespace std;

const int N = 200200;
int T, n, x;
int a[N], cnt[N], cc[N];

void solve() {
    scanf("%d%d", &n, &x);
    
    // Reset the count array
    for (int i = 0; i <= n + 1; i++) {
        cc[i] = cnt[i] = 0;
    }

    // Count occurrences of elements <= n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] <= n) {
            cc[a[i]]++;
        }
    }

    // Handle case where x is larger than n
    if (x > n) {
        int flg = 0;
        for (int i = 1; i <= n; ) {
            if (a[i] != flg) {
                break;
            }
            while (i <= n && a[i] == flg) {
                i++;
            }
            flg++;
        }
        printf("%d\n", flg);
        return;
    }

    // Try to find the maximum MEX
    for (int i = 0; i <= n; i++) {
        cnt[i % x] += cc[i];
        if (cnt[i % x] == 0) {
            printf("%d\n", i);
            return;
        }
        --cnt[i % x];
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}
