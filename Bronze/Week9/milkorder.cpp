#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=832
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    int N, M, K;
    fin >> N >> M >> K;
    bool init = false;
    int hierarchy[M];
    for(int i = 0; i < M; i++){
        fin >> hierarchy[i];
        if (hierarchy[i] == 1){
            init = true;
        }
    }
    map<int, int> placements;
    int positions[N];
    for(int i = 0; i < N; i++){
        positions[i] = -1;
    }
    for(int i = 0; i < K; i++){
        int a, b;
        fin >> a >> b;
        if (a == 1){
            fout << b;
            return 0;
        }
        placements[a] = b;
        positions[b-1] = a;
    }
    int count = 0;
    if (init == true){
        int position = 0;
        for(int i = 0; i < M; i++){
            if (hierarchy[i] == -1){
                break;
            }
            bool indemand = false;
            for(auto const &x : placements){
                if (x.first == hierarchy[i]){
                    indemand = true;
                    position = x.second - 1;
                    break;
                }
            }
            if (indemand == false){
                while(positions[position] != -1){
                    position++;
                }
                positions[position] = hierarchy[i];
            }
        }
        for(int i = 0; i < N; i++){
            if (positions[i] == 1){
                count = i+1;
            }
        }
    }
    else{
        int position = N-1;
        for(int i = M-1; i > -1; i--){
            bool indemand = false;
            for(auto const &x : placements){
                if (x.first == hierarchy[i]){
                    indemand = true;
                    position = x.second - 1;
                    continue;
                }
            }
            if (indemand == false){
                for(int j = position; j > -1; j--){
                    if (positions[j] == -1){
                        position = j;
                        positions[j] = hierarchy[i];
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if (positions[i] == -1){
                count = i + 1;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << positions[i] << endl;
    }
    fout << count;
}