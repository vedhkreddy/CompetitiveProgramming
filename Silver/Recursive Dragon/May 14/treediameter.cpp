#include <bits/stdc++.h>
using namespace std;

vector<int> graph[500000];

int diam(){

}

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}