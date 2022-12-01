#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c;
vector<int> v;

bool check(int num){ 
    int buses = 1;
    int earliest = v[0];
    int earliestindex = 0;
    for(int i = 0; i < n; i++){
        if (v[i] - earliest > num || i + 1 - earliestindex > c){
            earliestindex = i;
            buses++;
            earliest = v[i];
        }
    }
    return buses <= m;
}

int bsearch(){
    int lo = 0; int hi = v[n-1] - v[0];
    while(lo < hi){
        int mid = (lo + hi)/2;
        if (check(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    return lo;
}




int main(){
    ifstream cin(
        "convention.in"
    );
    ofstream cout("convention.out");
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << bsearch();
}