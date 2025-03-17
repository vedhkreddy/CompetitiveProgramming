#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int arraySize;
        cin >> arraySize;
        vector<ll> values(arraySize);
        for (int i = 0; i < arraySize; i++) cin >> values[i];
        
        map<ll, vector<ll>> adjacencyList;
        for (int i = 1; i < arraySize; i++) {
            ll start = values[i] + i;
            ll end = start + i;
            adjacencyList[start].push_back(end);
        }
        
        set<ll> visited;
        function<void(ll)> depthFirstSearch = [&](ll node) -> void {
            if (visited.count(node)) return;
            visited.insert(node);
            for (ll neighbor : adjacencyList[node]) {
                depthFirstSearch(neighbor);
            }
        };
        
        depthFirstSearch(arraySize);
        cout << *visited.rbegin() << "\n";
    }
    return 0;
}
