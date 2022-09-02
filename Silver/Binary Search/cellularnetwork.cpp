#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    //ifstream cin("test.in");
    //ofstream cout("test.out");
    vector<int> v;
    set<int> towers;
    int n, m;
    cin >> n >> m;
    long long towermax = -10000000000;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        towers.insert(a);
        if (a > towermax){
            towermax = a;
        }
    }
    long long max = -10000000000;
    for(int i = 0; i < n; i++){
        auto x = towers.begin();
        if (v[i] > towermax){
            x = towers.end();
            x--;
        } else {x = towers.lower_bound(v[i]);}
        if (x == towers.begin()){
            if (abs(*x - v[i]) > max){
                max = abs(*x - v[i]);
            }
        }
        else{
            auto y = x;
            x--;
            if (abs(*x - v[i]) > abs(*y - v[i])){
                x++;
            }
            if (abs(*x - v[i]) > max){
                max = abs(*x - v[i]);
            }
        }
    }
    cout << max;
}