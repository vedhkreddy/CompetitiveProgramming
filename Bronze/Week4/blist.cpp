#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int timeline[1001];
int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=856
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N;
    fin >> N;
    vector<vector<int>> intervals;
    for(int i = 0; i < N; i++){
        int a, b, c;
        fin >> a >> b >> c;
        intervals.push_back({a, b, c});
    }
    for(vector<int> v : intervals){
        for (int i = v[0]; i < v[1]; i++){
            timeline[i] += v[2];
        }
    }

    fout << *max_element(timeline, timeline+1001) << endl;;
}