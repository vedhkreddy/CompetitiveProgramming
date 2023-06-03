#include <bits/stdc++.h>
using namespace std;


vector<int> graph[500000];
bool visited[500000];
int maxnode = -1;
int maxdist = -1;


void dfs(int x, int dist){
    visited[x] = true;
    if (dist > maxdist){
        maxdist = dist;
        maxnode = x;
    }
    for (int i : graph[x]){
        if (visited[i] == false){
            dfs(i, dist+1);
        }
    }
}

int diam(){
    dfs(1, 0);
    int p1 = maxnode;
    maxdist = 0;
    fill(visited, visited + 500000, false);
    dfs(p1, 0);
    return maxdist;
}

int main(){
    //ifstream cin("test.in");
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << diam();
}