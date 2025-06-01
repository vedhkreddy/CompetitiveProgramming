#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define FOR(i,b) for (int i = 0; i < (b); i++)

const int mxn = 100005;
const int K = 10; // maximum j we care about
vector<int> adj[mxn];
int difficulty[mxn];
int enjoyment[mxn];
int dp[mxn][K+1]; // dp[node][j]: j-th highest difficulty along the path (1-indexed)

// We will use a priority queue (max-heap) for storing the top K values.
void dfsFill(int node, int parent, priority_queue<int>& pq) {
    // Add the current node's difficulty to the priority queue
    pq.push(difficulty[node]);
    // If the priority queue exceeds size K, remove the smallest element
    if (pq.size() > K) {
        pq.pop();
    }

    // Fill dp[node] with the top K maximum values from the priority queue
    priority_queue<int> temp = pq;
    int idx = 1;
    while (!temp.empty()) {
        dp[node][idx++] = temp.top();
        temp.pop();
    }

    // Recurse on the children
    for (int child : adj[node]) {
        if (child != parent) {
            dfsFill(child, node, pq);
        }
    }

    // After visiting all children, remove the current node's difficulty from the queue
    pq.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Note: In your input, node 1 is the root.
    for (int i = 0; i < n; i++){
        int p, d, e;
        cin >> p >> d >> e;
        int child = i + 2;  // because node 1 is root
        adj[p].push_back(child);
        difficulty[child] = d;
        enjoyment[child] = e;
    }
    
    // If needed, assign a difficulty for the root (node 1).
    difficulty[1] = 0;  // or another appropriate value
    enjoyment[1] = 0;   // similarly for enjoyment

    // We will start DFS from the root (node 1) with an empty priority queue.
    priority_queue<int> pq;
    dfsFill(1, -1, pq);
    
    // For example, if you want to print dp for each node:
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        for (int j = 1; j <= K; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
