#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> graph[500000];
vector<int> endpoints;
vector<int> endpoints1;

bool visited[500000];
int maxnode = -1;
int maxdist = -1;


void dfs(int x, int dist){
    visited[x] = true;
    if (dist > maxdist){
        endpoints.clear();
        maxdist = dist;
        maxnode = x;
        endpoints.push_back(x);
    }
    else if (dist == maxdist){
        endpoints.push_back(x);
    }
    for (int i : graph[x]){
        if (visited[i] == false){
            dfs(i, dist+1);
        }
    }
}

int32_t diam(){
    dfs(1, 0);
    int p1 = maxnode;
    maxdist = 0;
    endpoints1 = endpoints;
    endpoints.clear();
    fill(visited, visited + 500000, false);
    dfs(p1, 0);
    endpoints1.insert(endpoints1.end(), endpoints.begin(), endpoints.end());
    sort(endpoints.begin(), endpoints.end());
    return maxdist;
}

int32_t main(){
    //ifstream cin("test.in");
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int meter = diam();
    sort(endpoints.begin(), endpoints.end());
    bool x[500000];
    for (int i : endpoints1){
        x[i] = true;
    }
    for (int i = 1; i <= n; i++){
        if (x[i] == true){
            cout << meter + 1 << endl;
        }
        else{
            cout << meter << endl;
        }
    }
}