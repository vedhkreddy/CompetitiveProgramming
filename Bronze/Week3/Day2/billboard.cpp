#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int a, b, c, d, e, f, g, h, i, j, k, l;
    fin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    vector<int> first = {a, b, c, d};
    vector<int> second = {e, f, g, h};
    vector<int> truck = {i, j, k, l};
    set<pair<int, int>> squares_covered_billboards;
    for(int i = first[0]; i < first[2]; i++){
        for(int j = first[1]; j < first[3]; j++){
            squares_covered_billboards.insert(make_pair(i, j));
        }
    }
    for(int i = second[0]; i < second[2]; i++){
        for(int j = second[1]; j < second[3]; j++){
            squares_covered_billboards.insert(make_pair(i, j));
        }
    }
    int count = squares_covered_billboards.size();
    for(int i = truck[0]; i < truck[2]; i++){
        for(int j = truck[1]; j < truck[3]; j++){
            set<pair<int, int>> s = squares_covered_billboards;
            int size = s.size();
            s.insert(make_pair(i, j));
            if (size == s.size()){
                count--;
            }
        }
    } 
    fout << count << endl;
}