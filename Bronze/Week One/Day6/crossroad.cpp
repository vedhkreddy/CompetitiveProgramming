#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=711
    //simplified version of code
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    int n;
    int crossings = 0;
    set<int> ids;
    fin >> n;
    vector<vector<int>> biglist;
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        biglist.push_back({a,b});
    }

    for(vector<int> v : biglist){
        ids.insert(v[0]);
    }

    map<int, vector<int>> sightings;
    for(int i: ids){
        sightings[i] = {};
    }
    for(vector<int> v : biglist){
        sightings[v[0]].push_back(v[1]);
    }
    for(int i: ids){
        int cur = sightings[i][0];
        for (int j: sightings[i]){
            if (j != cur){
                crossings += 1;
                cur = j;    
            }
        }
    }
    fout << crossings;
}