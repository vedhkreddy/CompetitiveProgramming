#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int total = 0;
vector<int> graph[1000000];
bool visited[1000000];

void dfs(int x){
    visited[x] = true;
    total++;
    total += ceil(log2(size(graph[x])));
    for (int i : graph[x]){
        if (!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); 
        graph[b].push_back(a);
    }
    dfs(1);
    cout << total - 1 << endl;
}