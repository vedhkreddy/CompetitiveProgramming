#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

//ifstream cin("test.in");

bool visited[100005];
int counter = 0;
int nodestamps[100005];
vector<int> func[100005];
int node = 0;
set<int> uniqueletters;
bool automaticdone = false;

int dfs(int x, int prev){
    if (!visited[x]){
        nodestamps[x] = node;
        node++;
        counter++;
        visited[x] = true;
        dfs(func[x][0], x);
    }
    else{
        if (prev == x){
            return 0;
        }
        if (52 - size(uniqueletters) < 1){
            automaticdone = true;
            return 0;
        }
        counter++;
    }
    return 0;
}

void clear(){
    for (int i = 0; i < 100004; i++){
        visited[i] = 0; nodestamps[i] = 0; func[i].clear();
        
        counter = 0;
        node = 0;
    }
}

int solve(){
    string a; string b;
    cin >> a >> b;
    vector<int> v;
    vector<int> v1;
    for (char c : a){
        if (c == tolower(c)){
            v.push_back(int(c) - 97);
            uniqueletters.insert(int(c) - 97);
        }
        else{
            v.push_back(int(c) - 65 + 26);
            uniqueletters.insert(int(c) - 65 + 26);
        }
        
    }
    for (char c : b){
        if (c == tolower(c)){
            v1.push_back(int(c) - 97);
            uniqueletters.insert(int(c) - 97);
        }
        else{
            v1.push_back(int(c) - 65 + 26);
            uniqueletters.insert(int(c) - 65 + 26);
        }
    }
    for (int i = 0; i < size(a); i++){
        if (v[i] == v1[i]){
            counter--;
        }
        func[v[i]].push_back(v1[i]);
        if (size(func[v[i]]) > 1 && func[v[i]][0] == func[v[i]][1]){
            func[v[i]].pop_back();  
        }
        else if (size(func[v[i]]) > 1){
            cout << "-1" << endl;
            return 0;
        }
    }

    bool first = true;
    for (int i : v){
        if (!visited[i]){
            dfs(i, 0);
            if (automaticdone == true){
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << counter << endl;
    return 0;

}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        solve();
        clear();
    }

}