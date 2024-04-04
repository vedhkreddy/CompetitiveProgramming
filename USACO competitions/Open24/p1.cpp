#include <bits/stdc++.h>

using namespace std;
#define pb push_back
int n, k; 
priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<int, vector<int>> tt;
vector<int> adj[300005];
vector<int> cows;
int visited[300005];
void slip(int a, int i){
    if (tt.count(a) > 0){
        tt[a].pb(i);
    }
    else{
        tt[a] = {i};
    }
}
void dfs(int x){
    visited[x] = 1;
    for(int i : adj[x]){
        if (!visited[i]) dfs(i);
    }
}
int solve(){
    //ifstream cin("p1.in");
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if (i < k){
            pq.push(a);
            slip(a, i);
        }
        cows.pb(a);
    }
    int cowind = k;
    int lastpq = -1;
    int finalind = -1;
    while(true){
        int a = pq.top(); pq.pop();
        if (a == lastpq) continue;
        for(int i = 1; i < tt[a].size(); i++){
            adj[i].pb(tt[a][i-1]);
            adj[i-1].pb(tt[a][i]);
        }
        for(int i : tt[a]){
            if (cowind != n){
                slip(a + cows[cowind], i);
                pq.push(a + cows[cowind]);
                cowind++;
            }
            else{
                //edges have already been added
                //all we need to do is call dfs on any node within and then its gonna work
                cout << a << endl;
                return i;
                
            }
        }
        lastpq = a;
    }

}

int main() {
    dfs(solve());
    for(int i = 0; i < k; i++){
        cout << visited[i];
    }
}