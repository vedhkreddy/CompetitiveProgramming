#include <iostream>
#include <fstream> 
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(pair<int, int> p, pair<int, int> p1){
    return p.second < p1.second;
}

vector<int> points;
map<int, int> compression;
map<int, int> intervals1;
map<int, int> intervals2;
int vital[2000001] = {0};

int main(){
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        points.push_back(a);
        points.push_back(b);
        intervals1[a] = b;
        intervals2[b] = a;
    }
    sort(points.begin(), points.end());
    int num = 0;
    for (int i = 0; i < points.size(); i++){
        if (intervals1.count(points[i])){
            compression[points[i]] = num;
            num++;
        }
    }
    set<pair<int, int>,bool(*)(pair<int, int>, pair<int, int>)> v(cmp);
    int onduty = 0;
    int fullcount = 0;
    for (int i = 0; i < points.size(); i++){
        if (onduty > 0){
            fullcount += (points[i] - points[i-1]);
        }
        if (onduty == 1){
            auto x = v.begin();
            pair<int, int> p = *x;
            vital[compression[p.first]] += (points[i] - points[i-1]);
        }
        if (intervals2.count(points[i])){
            auto it = v.begin();
            v.erase(it);
        }
        else{
            v.insert(make_pair(points[i], intervals1[points[i]]));
        }
        onduty = v.size();
    }
    int min = 1000000000;
    for (int i = 0; i < points.size()/2; i++){
        if (vital[i] < min){
            min = vital[i];
        }
    }

    fout << fullcount - min;
}