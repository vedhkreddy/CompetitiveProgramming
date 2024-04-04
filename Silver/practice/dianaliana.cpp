#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int M, N, K, S, W, a[500500], b[500500], st[500500];

int cnt[500500], t[500500], numhit, numt;

void add(int x) {
    cnt[x]++;
    if (cnt[x] == t[x]) numhit++;
}

void rem(int x) {
    if (cnt[x] == t[x]) numhit--;
    cnt[x]--;
}

int main() {
    cin >> M >> K >> N >> S;

    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < S; i++) {
        cin >> b[i];
        t[b[i]]++;
    }

    for (int i = 0; i < 500500; i++) {
        if (t[i]) {
            numt++;
        }
    }

    int r = 0;

    for (int l = 0; l < M; l++) {
        while (r < M && numhit < numt) {
            add(a[r++]);
        }
        st[l] = numhit == numt ? r : -1;
        rem(a[l]);
    }

    for (int i = 0; i < M; i++) {
        if (st[i] != -1) {
            int num_fix = i % K;
            int num_rem = max(0, st[i] - (i + K)), u = 0;

            if (num_fix + num_rem > M - N * K) continue;

            cout << num_fix + num_rem << endl;

            for (int j = 0; j < num_fix; j++) {
                cout << j + 1 << " ";
            }

            for (int j = i; j < st[i]; j++) {
                if (t[a[j]]) {
                    t[a[j]]--;
                } else if (u < num_rem) {
                    cout << j + 1 << " ";
                    u++;
                }
            }

            for (int j = 0; j < 500500; j++) {
                assert(t[j] == 0);
            }

            return 0;
        }
    }

    cout << "-1" << endl;

    return 0;
}
