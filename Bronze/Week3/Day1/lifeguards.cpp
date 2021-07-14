#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int positions[1000];

int tally(int curpositions[1000]){
    int tallycount = 0;
    for(int i = 0; i < 1000; i++){
        if (curpositions[i] > 0){
            tallycount++;
        }
    }
    return tallycount;
}

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=784
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int N;
    fin >> N;
    vector<pair<int, int>> shifts;
    for (int i = 0; i < N; i++){
        int a,b;
        fin >> a >> b;
        shifts.push_back(make_pair(a,b));
    }
    for(pair<int, int> p : shifts){
        for(int i = p.first-1; i < p.second-1; i++){
            positions[i]++;
        }
    }
    int bigcount = 0;
    for (pair<int, int> p : shifts){
        int count = tally(positions);
        for(int i = p.first-1; i < p.second-1; i++){
            if (positions[i] == 1){
                count--;
            }
        }
        if (count > bigcount){
            bigcount = count;
        }
    }
    fout << bigcount << endl;
}