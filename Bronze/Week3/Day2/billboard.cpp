#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=759
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int a, b, c, d, e, f, g, h, i, j, k, l;
    fin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    vector<int> first = {a, b, c, d};
    vector<int> second = {e, f, g, h};
    vector<int> truck = {i, j, k, l};
    set<pair<int, int>> squares_covered_billboards;
    int count = (first[3] - first[1]) * (first[2] - first[0]) + (second[3] - second[1]) * (second[2] - second[0]);
    for(int i = second[0]; i < second[2]; i++){
        for(int j = second[1]; j < second[3]; j++){
            if (i >= first[0] && i < first[2] && j >= first[1] && j < first[3]){
                count--;
            }
        }
    } 
    for(int i = truck[0]; i < truck[2]; i++){
        for(int j = truck[1]; j < truck[3]; j++){
            if (i >= first[0] && i < first[2] && j >= first[1] && j < first[3]){
                count--;
            }
            else if (i >= second[0] && i < second[2] && j >= second[1] && j < second[3]){
                count--;
            }
            else{}
        }
    } 
    fout << count << endl;
}

