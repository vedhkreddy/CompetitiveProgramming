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
    map<int, vector<int>> sightings;

    fin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        if (sightings.find(a) != sightings.end()){
            if (sightings[a].back() != b){
                crossings += 1;
            }
            sightings[a].push_back(b);
        }
        else{
            sightings[a] = {b};
        }
    }
    fout << crossings;
}