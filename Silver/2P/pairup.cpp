#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define pi pair<int, int>

int cmp(pi a, pi b){
    return a.second < b.second;
}

int main(){
    vector<pi> v;
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++){
        pi p;
        fin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int p1 = 0;
    int p2 = n-1;
    int time = 0;
    while (p1 <= p2){
        int curtime = 0;
        if (v[p1].first < v[p2].first){
            v[p2].first -= v[p1].first;
            curtime = v[p2].second + v[p1].second;
            p1++;
        }
        else if (v[p1].first > v[p2].first){
            v[p1].first -= v[p2].first;
            curtime = v[p2].second + v[p1].second;
            p2--;
        }
        else{
            curtime = v[p2].second + v[p1].second;
            p1++;
            p2--;
        }
        if (curtime > time){
            time = curtime;
        }
    }
    fout << time;
}