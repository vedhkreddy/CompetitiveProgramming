#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

//http://usaco.org/index.php?page=viewproblem2&cpid=1159
//connected components + binary search + dfs
ifstream fin("testing.in");

vector<int> paths[1000000];
int visited[1000000];

void dfs(int x, int color, int n){
    visited[x] = color;
    for (int i : paths[x]){
        if (visited[i] == 0){
            dfs(i, color, n);
        }
    }
}

int bsearch(int a, vector<int> v){
    auto x = lower_bound(v.begin(), v.end(), a);
    auto y = x;
    y--;
    //cout << *(v.begin()) << endl;
    int al = *x;
    int als = *y;
    if (x == v.begin()){
        return *x;
    }
    else if (abs(*x - a) < abs((*y - a))){
        return *x;
    }
    else{
        return *y;
    }
}
int solve(){
    
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int i1, i2;
        fin >> i1 >> i2;
        i1--;
        i2--;
        paths[i1].push_back(i2);
        paths[i2].push_back(i1);
    }
    
    dfs(0, 1, n);
    if (visited[0] == visited[n-1]){
        cout << "0" << endl;
        return 0;
    }
    dfs(n-1, 2, n);
    

    //cout << visited[0] << " " << visited[n-1] << endl;
    vector<int> c1;
    vector<int> c2;

    for (int j = 0; j < n; j++){
        if (visited[j] == 1){
            c1.push_back(j);
            //cout << j << endl;
        }
        if (visited[j] == 2){
            c2.push_back(j);
        }
    }

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    vector<int> answers;
    for (int i = 0; i < n; i++){
        if (visited[i] != 0){
            if (visited[i] == 1){
                int index = bsearch(i, c2);
                int asdf = abs(index - i);
                answers.push_back(asdf * asdf); 
            }
            else{
                int index = bsearch(i, c1);
                answers.push_back(abs(index - i) * abs(index - i));
            }
        }
        else{
            int index1 = bsearch(i, c1);
            int index2 = bsearch(i, c2);
            int ans = (abs(index1 - i) * abs(index1 - i)) + (abs(index2 - i) * abs(index2 - i));
            answers.push_back(abs(index1 - i) * abs(index1 - i) + abs(index2 - i) * abs(index2 - i));
        }
    }
    auto x = min_element(answers.begin(), answers.end());
    for (int i : answers){
        cout << i << endl;
    }
    cout << *x << endl;
    return 0;
}

void erase(){
    for(int i = 0; i < 1000000; i++){
        visited[i] = 0;
        paths[i].clear();
    }
}

int main(){
    int t; fin >> t;
    for (int i = 0; i < t; i++){
        erase();
        solve();
    }
}