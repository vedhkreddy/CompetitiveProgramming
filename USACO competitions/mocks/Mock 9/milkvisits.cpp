#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int type[100005];
vector<int> roads[100005];
int componentindexes[100005];
vector<int> prefs[100005];
int visited[100005];
int comptype[100005];

int component = 0;
//0 = holstein, 1 = guernsey
void dfs(int x, int color){
    visited[x] = true;
    componentindexes[x] = component;
    //cout << x << " ";
    for (int a : roads[x]){
        if (!visited[a] && type[a] == color){
            dfs(a, color);
        }
    }
}

int main(){
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int index = 0;
    for (char c : s){
        if (c == 'G'){
            type[index] = 1;
        }
        index++;
    }
    for (int i = 0 ; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    for (int i = 0; i < m; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        a--; b--;
        int d = 0;
        if (c == 'G'){
            d = 1;
        }
        prefs[i] = {a, b, d};
    }
    for (int i = 0; i < n; i++){
        //cout << type[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i, type[i]);
        }
        comptype[component] = type[i];
        //cout << endl;
        component++;
    }
    for (int i = 0 ; i < m; i++){
        if (componentindexes[prefs[i][0]] != componentindexes[prefs[i][1]]){
            cout << 1;
        }
        else if(comptype[componentindexes[prefs[i][0]]] == prefs[i][2]){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
}
