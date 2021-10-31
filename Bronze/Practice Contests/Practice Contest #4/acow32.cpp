#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main(){
    cout << "here";
    ifstream fin("acow3.in");
    int N, M;
    fin >> N >> M;
    int grid[N][M];
    int id = 10000;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            char a;
            fin >> a;
            cout << a;
            if (a == 'C'){
                cout << "here";
                a = id;
                id++;
            }
            grid[i][j] = a;
        }
    }
    map<pair<int, int>, vector<pair<int, int>>> poss;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (grid[i][j] == 'G'){
                vector<int> cur;
                if (grid[i + 1][j] >= 10000){
                    cur.push_back(grid[i+1][j]);
                }
                if (grid[i - 1][j] >= 10000){
                    cur.push_back(grid[i-1][j]);
                }
                if (grid[i][j - 1] >= 10000){
                    cur.push_back(grid[i][j - 1]);
                }
                if (grid[i][j + 1] >= 10000){
                    cur.push_back(grid[i][j + 1]);
                }
                for (int i = 0; i < cur.size() - 1; i++){
                    for (int j = 1; j < cur.size(); j++){
                        poss[make_pair(i, j)].push_back(make_pair(cur[i], cur[j]));
                    }
                }
            }
        }
    }
    vector<pair<int, int>> restricted;
    vector<pair<int, int>> deletions;
    int count = 0;
    for (auto const &x : poss){
        if (x.second.size() == 1){
            bool stop = false;
            for (pair<int, int> r : restricted){
                if (make_pair(x.second[0].first, x.second[0].second) == r){
                    deletions.push_back(make_pair(x.first.first, x.first.second));
                    stop = true;
                    break;
                }
            }
            if (stop == false){
                restricted.push_back(make_pair(x.second[0].first, x.second[0].second));
                count++;
                deletions.push_back(make_pair(x.first.first, x.first.second));
            }
        }
    }
    for(pair<int, int> p : deletions){
        poss.erase(p);
    }
    for (auto const &x : poss){
        bool allgone = true;
        for (pair<int, int> z : x.second){
            for (pair<int, int> y : restricted){
                if (z != y){
                    allgone = false;
                }
            }
        }
        if (allgone == false){
            count++;
        }
    }
    cout << count;
}