#include <iostream>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

int query(int u, int v) {
    cout << "? " << u + 1 << ' ' << v + 1 << '\n';
    int x; 
    cin >> x;
    return x - 1;  // Adjust for 0-based indexing
}

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> edges;  // To store the resulting edges
    vector<int> component(n);
    iota(component.begin(), component.end(), 0);  // Initialize component to [0, 1, 2, ..., n-1]

    // Helper function to add an edge and update components
    auto addEdge = [&](int u, int v) {
        edges.push_back({u, v});
        vector<int> candidates;
        for (int i = 0; i < n; i++) {
            if (component[i] == component[v]) {
                candidates.push_back(i);
            }
        }
        for (int i : candidates) {
            component[i] = component[u];  // Merge the components of u and v
        }
    };

    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0;
        while (component[v] == component[u]) v++;  // Ensure u and v are from different components
        int x;
        // Repeatedly query until we find the correct u
        while ((x = query(u, v)) != u) {
            if (component[u] == component[x]) {
                u = x;
            } else {
                v = x;
            }
        }
        addEdge(u, v);  // Add the edge between u and v
    }

    // Output the edges
    cout << "!";
    for (auto [u, v] : edges) {
        cout << ' ' << u + 1 << ' ' << v + 1;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
