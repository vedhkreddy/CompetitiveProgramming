#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int solve(vector<vector<char>> grid, int N, int M){    
    int count = 0;
    set<vector<pair<int, int>>> pairs;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (grid[i][j] == 'G'){
                vector<pair<int, int>> cur;
                if (i != 0){
                    if (grid[i-1][j] == 'C'){
                        cur.push_back(make_pair(i-1, j));
                    }
                }
                if (i != N-1){
                    if (grid[i+1][j] == 'C'){
                        cur.push_back(make_pair(i+1, j));
                    }
                }
                if (j != 0){
                    if (grid[i][j-1] == 'C'){
                        cur.push_back(make_pair(i, j-1));
                    }
                }
                if (j != M-1){
                    if (grid[i][j+1] == 'C'){
                        cur.push_back(make_pair(i, j+1));
                    }
                }
                if (size(cur) > 2){
                    //means there is two opposite (cannot meet elsewhere) so increment count
                    count++;
                }
                if (size(cur) == 2){
                    //add to set to avoid double counting
                    auto i = cur[0];
                    auto j = cur[1];
                    if (i.first > j.first){
                        auto tmp = j;
                        j = i;
                        i = tmp;
                    }
                    else if (i.first == j.first){
                        if (i.second > j.second){
                            auto tmp = j;
                            j = i;
                            i = tmp;
                        }
                    }
                    vector<pair<int, int>> v;
                    v.push_back(i);
                    v.push_back(j);
                    pairs.insert(v);
                }
            }
        }
    }
    return count + pairs.size();
}


int main(){
    //ifstream cin("acow3.in");
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid;
    for (int i = 0; i < N; i++){
        vector<char> row;
        for (int j = 0; j < M; j++){
            char a;
            cin >> a;
            row.push_back(a);
        }
        grid.push_back(row);
    }
    cout << solve(grid, N, M);
}