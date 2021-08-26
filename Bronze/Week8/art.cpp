#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=737
    ifstream fin("art.in");
    ofstream fout("art.out");
    int N;
    fin >> N;
    int grid[N][N];
    set<int> showing;
    set<int> excluded;
    map<int, vector<int>[2]> coordinates;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char a;
            fin >> a;
            grid[i][j] = int(a) - 48;
            if (grid[i][j] != 0){
                coordinates[grid[i][j]][0].push_back(i);
                coordinates[grid[i][j]][1].push_back(j);
                showing.insert(grid[i][j]);
            }
        }
    }
    for(int i : showing){
        int minx = *min_element(coordinates[i][0].begin(), coordinates[i][0].end());
        int maxx = *max_element(coordinates[i][0].begin(), coordinates[i][0].end());
        int miny = *min_element(coordinates[i][1].begin(), coordinates[i][1].end());
        int maxy = *max_element(coordinates[i][1].begin(), coordinates[i][1].end());
        for(int j = minx; j <= maxx; j++){
            for(int k = miny; k <= maxy; k++){
                if (grid[j][k] != i){
                    excluded.insert(grid[j][k]);
                }
            }
        }
    }
    int count = 0;
    for(int i : showing){
        bool found = false;
        for (int j : excluded){
            if (j == i){
                found = true;
            }
        }
        if (found == false){
            count++;
        }
    }
    fout << count;
}