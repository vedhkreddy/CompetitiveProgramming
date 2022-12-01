#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(make_pair(a, b), i+1));
    }

    sort(v.begin(), v.end());
    auto cur = v[0];
    priority_queue<pair<int, pair<int, int>>> p;
    while (true){
        for (int i = 0; i < n; i++){
            if (v[i].first.first > cur.first.first + cur.first.second){

            }
            else{
                p.push()
            }
        }
    }
}   