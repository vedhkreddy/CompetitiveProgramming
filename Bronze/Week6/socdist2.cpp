#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;

int solve(map<int, int> cows){
    int R = 10e6;
    map<int, int> :: iterator cur;
    for(cur = cows.begin(); cur != cows.end(); cur++){
        auto x = cows.end();
        x--;
        if (cur == x){
            break;
        }
        auto after = cur;
        cur++;
        if (cur->second != after->second){
            if (abs(after->first - cur->first) < R){
                R = abs(after->first - cur->first);
                cur++;
            }
        }
        cur--;
    }

    int count = 1;
    for(cur = cows.begin(); cur != cows.end(); cur++){
        if (cur == cows.end()--){
            break;
        }
        auto after = cur;
        cur++;
        if (cur->second == 1 && cur->first - after->first >= R){
            count++;
        }
        cur--;
    }

    return count;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1036
    ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");
    int N;
    fin >> N;
    map<int, int> cows;
    for (int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        cows[a] = b;
    }

    int sol = solve(cows);
    fout << sol;
}