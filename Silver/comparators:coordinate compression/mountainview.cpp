#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main(){
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    int n; fin >> n;
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        order.push_back(make_pair(a-b, a+b));
    }
    sort(order.begin(), order.end(), cmp);
    int maxmin = 0;
    int count = 0;
    for (pair<int, int> p : order){
        if (p.second > maxmin){
            count++;
            maxmin = p.second;
        }
    }
    fout << count;
}