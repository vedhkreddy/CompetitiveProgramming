#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 1;

int N, a, b;
int down[maxN], up[maxN], best[maxN];
vector<int> graph[maxN];

void dfs1(int u = 1, int p = 0) {
    for (int v : graph[u]) {
        if (v != p) {
            dfs1(v, u);
            down[u] = max(down[u], down[v] + 1);
        }
    }
}

void dfs2(int u = 1, int p = 0) {
    int first = 0, second = 0;
    for (int v : graph[u]) {
        if (v != p) {
            if (down[v] >= down[first]) {
                second = first;
                first = v;
            } else if (down[v] > down[second]) {
                second = v;
            }
        }
    }

    for (int v : graph[u]) {
        if (v != p) {
            up[v] = max(up[v], up[u] + 1);
            if (v == first) {
                if (second != 0) {
                    up[v] = max(up[v], down[second] + 2);
                }
            } else if (first != 0) {
                up[v] = max(up[v], down[first] + 2);
            }
            dfs2(v, u);
        }
    }

    best[u] = max(up[u], down[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1();
    dfs2();

    for (int i = 1; i <= N; i++) {
        cout << best[i] << " ";
    }
    cout << endl;

    return 0;
}
