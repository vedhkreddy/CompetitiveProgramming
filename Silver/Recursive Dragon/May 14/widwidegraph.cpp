#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 228;

vector<int> graph[N];

void dfs(int v, int par, int h, vector<int>& d) {
    d[v] = h;
    for (int i : graph[v]) {
        if (i != par) {
            dfs(i, v, h + 1, d);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);

    int max_d1 = -1;
    int a = -1;
    for (int i = 0; i < n; ++i) {
        if (d1[i] > max_d1) {
            max_d1 = d1[i];
            a = i;
        }
    }

    dfs(a, -1, 0, d1);

    int max_d2 = -1;
    int b = -1;
    for (int i = 0; i < n; ++i) {
        if (d1[i] > max_d2) {
            max_d2 = d1[i];
            b = i;
        }
    }

    dfs(b, -1, 0, d2);

    for (int i = 0; i < n; ++i) {
        d2[i] = max(d2[i], d1[i]);
    }

    sort(d2.begin(), d2.end());

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (ans < n && d2[ans] < i) {
            ++ans;
        }
        cout << min(n, ans + 1) << ' ';
    }
    cout << '\n';

    return 0;
}
