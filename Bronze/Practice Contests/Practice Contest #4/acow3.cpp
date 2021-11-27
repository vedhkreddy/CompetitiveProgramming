#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

set<vector<pair<int, int>>> makepairs(vector<vector<char>> grid, int N, int M){    
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
                for (pair<int, int> i : cur){
                    for (pair<int, int> j : cur){
                        if (i != j){
                            vector<pair<int, int>> singlepair;
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
                            singlepair.push_back(i);
                            singlepair.push_back(j);
                            //cout << i.first << " " << i.second << " " << j.first << " " << j.second << endl;
                            pairs.insert(singlepair);
                        }
                    }
                }
            }
        }
    }
    return pairs;
}


int main(){
    ifstream cin("acow3.in");
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
    int count = 0;
    set<vector<pair<int, int>>> pairs = makepairs(grid, N, M);
    while (pairs.size() != 0){
        vector<vector<pair<int, int>>> deletions;        
        for (auto v : pairs){
            if (v[0].first == v[1].first){
                if (grid[v[0].first][(v[0].second + 1)] == 'G'){
                    count++;
                    //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                    grid[v[0].first][(v[0].second + 1)] = '.';
                }
                deletions.push_back(v);
            }
            else if (v[0].second == v[1].second){
                if (grid[v[0].first + 1][v[0].second] == 'G'){
                    count++;
                    //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                    grid[v[0].first + 1][v[0].second] = '.';
                }
                deletions.push_back(v);
            }
            else{
                bool first = grid[v[0].first][v[1].second] == 'G';
                bool second = grid[v[1].first][v[0].second] == 'G';
                if (first == true && second == true){
            
                }
                else if (first == true){
                    grid[v[0].first][v[1].second] = '.';
                    count++;
                    //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                    deletions.push_back(v);
                }
                else if (second == true){
                    grid[v[1].first][v[0].second] = '.';
                    count++;
                    //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                    deletions.push_back(v);
                }
                else{
                    deletions.push_back(v);
                }
            }
        }
        for (auto v : deletions){
            pairs.erase(v);

        }
        for (auto v : pairs){
            bool first = grid[v[0].first][v[1].second] == 'G';
            bool second = grid[v[1].first][v[0].second] == 'G';
            if (first == true){
                grid[v[0].first][v[1].second] = '.';
                count++;
                //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                deletions.push_back(v);
            }
            else{
                grid[v[1].first][v[0].second] = '.';
                count++;
                //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
                deletions.push_back(v);
            }
            break;
        }
        for (auto v : deletions){
            pairs.erase(v);
        }
    }
    cout << count;
}