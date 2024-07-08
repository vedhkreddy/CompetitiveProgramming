#include <bits/stdc++.h>
using namespace std;

struct MinimizeX {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; 
    }
};

struct MaximizeX {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

struct MinimizeY {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

struct MaximizeY {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

void solve(){
    int a; int b; int n; int m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MinimizeX> pqMinX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaximizeX> pqMaxX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MinimizeY> pqMinY;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaximizeY> pqMaxY;
    map<pair<int, int>, int> done;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        pqMaxX.push(make_pair(x, y));
        pqMinX.push(make_pair(x, y));
        pqMaxY.push(make_pair(x, y));
        pqMinY.push(make_pair(x, y));
        done[make_pair(x, y)] = 0;
    }
    int basex = 0; int basey = 0;
    int alice = true;
    int aliceres = 0; int bobres = 0;
    for(int i = 0; i < m; i++){

        char c; int k; cin >> c; cin >> k;
        if (c == 'U'){
            while(true){
                if (pqMinY.size() == 0){
                    break;
                }
                pair<int, int> y = pqMinY.top();
                if (done[y] == 1){
                    pqMinY.pop(); continue;
                }
                else if (y.second < basey + k){
                    pqMinY.pop();
                    done[y] = 1;
                    if (alice == true){
                        aliceres++;
                    }
                    else{
                        bobres++;
                    }
                    basey += k;
                    continue;
                }
                else{
                    break;
                }
            }
        }
        if (c == 'D'){
            while(true){
                pair<int, int> y = pqMaxY.top();
                if (done[y] == 1){
                    pqMaxY.pop(); continue;
                }
                else if (y.second < a + k){
                    pqMaxY.pop();
                    done[y] = 1;
                    if (alice == true){
                        aliceres++;
                    }
                    else{
                        bobres++;
                    }
                    continue;
                }
                else{
                    break;
                }
            }
        }
        if (c == 'U'){
            while(true){
                pair<int, int> y = pqMinY.top();
                if (done[y] == 1){
                    pqMinY.pop(); continue;
                }
                else if (y.second < basey + k){
                    pqMinY.pop();
                    done[y] = 1;
                    if (alice == true){
                        aliceres++;
                    }
                    else{
                        bobres++;
                    }
                    continue;
                }
                else{
                    break;
                }
            }
        }
        if (c == 'U'){
            while(true){
                pair<int, int> y = pqMinY.top();
                if (done[y] == 1){
                    pqMinY.pop(); continue;
                }
                else if (y.second < basey + k){
                    pqMinY.pop();
                    done[y] = 1;
                    if (alice == true){
                        aliceres++;
                    }
                    else{
                        bobres++;
                    }
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}