#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> adj_list[5000];
bool visited[5000];
vector<int> needed;


void dfs(int node){
    visited[node] = true;
    for (int u : adj_list[node]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

void close(int node){
    adj_list[node].clear();
    int count = 0;
    for (int i : needed){
        if (i == node){
            break;
        }
        count++;
    }
    needed.erase(needed.begin() + count);
    for (int i = 0; i < 5000; i++){
        visited[i] = false;
    }
}

bool check(){
    dfs(needed[0]);
    for (int i : needed){
        if (!visited[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("closing.in"); 
    ofstream fout("closing.out");
    int n, m; 
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        needed.push_back(i);
    }
    if (check()){
        fout << "YES" << endl;
    }
    else{
        fout << "NO" << endl;
    }
    for (int i = 0; i < n-1; i++){
        int a;
        fin >> a;
        close(a);
        if (check()){
            fout << "YES" << endl;
        }
        else{
            fout << "NO" << endl;
        }
    }
}
