#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int solve(multimap<int, int> times){
    int time = 0;
    for(auto const& x : times){
        if (time <= x.first){
            time = x.first + x.second;
        }
        else{
            time += x.second;
        }
    }
    return time;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=713
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int N;
    fin >> N;
    multimap<int, int> times;
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        times.insert(pair <int, int> (a, b));
    }
    int solution = solve(times);
    fout << solution;
}