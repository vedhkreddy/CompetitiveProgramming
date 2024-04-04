#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 5;
vector<int> adj[mxn];
vector<int> ans;
int visited[mxn];

int main(){
    int n; cin >> n;
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<int, std::vector<int>, std::greater<int> > p;
    p.push(1);
    visited[1] = true;
    while(p.size() != 0){
        int x = p.top();
        p.pop();
        ans.push_back(x);
        for(int i : adj[x]){
            if (!visited[i]){
                p.push(i);
                visited[i] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}