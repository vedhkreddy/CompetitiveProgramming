#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];
int visited[1000000];
vector<int> topsort;
bool cycle = 0;

void dfs(int x){
    visited[x] = 1;
    for (int i : adj[x]){
        if (visited[i] == 1){
            cycle = 1;
            return;
        }
        if (visited[i] == 0){
            dfs(i);
        }
    }
    visited[x] = 2;
    topsort.push_back(x);
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if (visited[i] == 0){
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    if (cycle == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        cout << topsort[i] << " ";
    }
}