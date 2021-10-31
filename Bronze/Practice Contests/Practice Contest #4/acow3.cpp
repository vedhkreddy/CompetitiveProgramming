#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    char grid[N][M];
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }
    map<pair<int, int>, vector<pair<pair<int, int>, pair<int, int>>>> possibilities;
    vector<pair<int, int>> gs;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (grid[i][j] == 'G'){
                vector<pair<int, int>> cur;
                if (grid[i][j + 1] == 'C'){
                    cur.push_back(make_pair(i, j + 1));
                }
                if (grid[i][j - 1] == 'C'){
                    cur.push_back(make_pair(i, j - 1));
                }
                if (grid[i - 1][j] == 'C'){
                    cur.push_back(make_pair(i - 1, j));
                }
                if (grid[i + 1][j] == 'C'){
                    cur.push_back(make_pair(i + 1, j));
                }
                if (cur.size() == 2){
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[1]));
                    
                }
                else if (cur.size() == 3){
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[1]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[2]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[1], cur[2]));
                }
                else if (cur.size() == 4){
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[1]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[2]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[0], cur[3]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[1], cur[2]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[1], cur[3]));
                    possibilities[make_pair(i, j)].push_back(make_pair(cur[2], cur[3]));
                }
                else{
                    continue;
                }
                gs.push_back(make_pair(i, j));
            }
        }
    }
    cout << possibilities.size();
}