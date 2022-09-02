#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> graph[1000000];
int first = 0;
int second = 0;
int connections[1000000];
int color[1000000];
bool vis[1000000];

void dfs(int node, int cur){
    vis[node] = true;
    color[node] = cur;
    if (cur == 0){
        first++;
    }
    else{
        second++;
    }
    for (int i : graph[node]){
        if (!vis[i]){
            if (cur == 0){
                dfs(i, 1);
            }
            else{
                dfs(i, 0);
            }
        }
    }
}

int main(){
    //ifstream cin("test.in");
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        connections[a]++;
        connections[b]++;
    }
    dfs(1, 0);
    long long add = 0;
    //cout << first << " " << second;
    for(int i = 1; i <= n; i++){
        if (color[i] == 0){
            add += max(second - connections[i], 0);
        }
        else{
            add += max(first - connections[i], 0);
        }
    }
    cout << add / 2;
}
