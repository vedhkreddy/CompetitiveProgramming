#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int solve(map<char, vector<int>> crosspoints){
    int count = 0;
    for(char i = 'A'; i <= 'Z'; i++){
        for(char j = i + 1; j <= 'Z'; j++){
            int 
            x = crosspoints[i][0];
            int y = crosspoints[i][1];
            int z = crosspoints[j][0];
            int a = crosspoints[j][1];

            if ((z > x && a > y && z < y) || (x > z && x < a && y > a)){
                count++;
            }
        }
    }
    return count; 
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=712
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    map<char, vector<int>> crosspoints;
    for(int i = 0; i < 52; i++){
        char a;
        fin >> a;
        crosspoints[a].push_back(i);
    }
    int solution = solve(crosspoints);
    fout << solution;
}