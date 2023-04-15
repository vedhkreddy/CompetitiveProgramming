#include <bits/stdc++.h>
using namespace std;

int TC;

bool check(int w, int X, int Y, int N, vector<int>& A, vector<int>& B, vector<int>& C) {
    int lx = max(1, X - w);
    int hx = min(X + Y - w - 1, X);
    for (int i = 0; i < N; i++) {
        int a = A[i], b = B[i], c = C[i];
        int d = X + Y - w;
        if (b - a > 0) {
            lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
        } else if (a - b > 0) {
            hx = min(hx, (c - b * d) / (a - b));
        } else {
            if (a * d > c) {
                return false;
            }
        }
    }
    return (lx <= hx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N), B(N), C(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }
        int lo = 0;
        int hi = X + Y - 2;
        while (hi > lo) {
            int mid = (lo + hi) / 2;
            if (check(mid, X, Y, N, A, B, C)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
    return 0;
}
