#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct recordchange{
    int id;
    int hour;
    int change;
}; 

bool cmp(recordchange a, recordchange b){
    return a.hour < b.hour;
}

int main(){
    int n, g;
    cin >> n >> g;
    vector<recordchange> v;
    for (int i = 0; i < n; i++){
        recordchange cur;
        cin >> cur.id >> cur.hour >> cur.change;
    }

    sort(v.begin(), v.end(), cmp);
    map<int, int> ondisplay;
    map<int, int> number;
    for (int i = 0; i < n; i++){
        ondisplay[v[i].id]
    } 

}