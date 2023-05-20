#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 50;
vector<int> adjlist[maxN];
vector<int> newgraph[maxN];
bool cycle = false;
int visited[maxN];
vector<int> toposort;
vector<int> curnodes;
vector<int> weights;
int dp[maxN];

void dfs(int x){
    visited[x] = 1;
    for (int i : newgraph[x]){
        if (visited[i] == 1){
            cycle = 1;
            return;
        }
        if (visited[i] == 0){
            dfs(i);
        }
    }
    visited[x] = 1;
    toposort.push_back(x);
}

void clear(){
    for (int i = 0; i < maxN; i++){
        newgraph[i].clear();
        visited[i] = 0;
    }
    cycle = false;
    toposort.clear();
    curnodes.clear();
}

void graphconstruct(int x, int n){
    for (int i = 0; i < n; i++){
        if (weights[i] > x){
            curnodes.push_back(i);
        }
    }
    for(int i : curnodes){
        for (int j : adjlist[i]){
            if (weights[j] <= x){
                newgraph[i].push_back(j);
            }
        }
    }
}

bool check(int x, int n, int k){
    clear();
    graphconstruct(x, n);
    for (int i : curnodes){
        if (visited[i] == 0){
            dfs(i);
        }
    }
    if (cycle == true){
        return true;
    }

    for (int i = 0; i < toposort.size(); i++){
        if (i == 0){
            dp[toposort[i]] = 1;
        }
        else{
            int max = -1;
            for (int j : newgraph[toposort[i]]){
                if (j > max){
                    max = j;
                }
            }
            dp[toposort[i]] = max + 1;
        }
    }
    reverse(toposort.begin(), toposort.end());
    return dp[toposort[0]] > k;
}

int main(){
    cout << "here";
    int n; int m; int k;
    ifstream cin("test.in");
    cout << "here";
    
    cin >> n >> m >> k;
    int lo = 0; int hi = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        weights.push_back(a);
        hi = max(hi, a);
    }
    cout << "here";

    for (int i = 0; i < m; i++){
        int b, c;
        cin >> b >> c;
        adjlist[b].push_back(c);
    }

    cout << "here";
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, n, k)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }

    cout << lo;
    
}