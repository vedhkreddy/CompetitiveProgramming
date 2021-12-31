#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    //ifstream cin("walkinghome.in");
    int T;
    cin >> T;
    int N[T];
    int K[T];
    vector<vector<vector<char>>> grids;
    for (int i = 0; i < T; i++){
        cin >> N[i] >> K[i];
        vector<vector<char>> grid;
        for (int j = 0; j < N[i]; j++){
            vector<char> row;
            for (int k = 0; k < N[i]; k++){
                char a;
                cin >> a;
                row.push_back(a);
            }
            grid.push_back(row);
        }
        grids.push_back(grid);
    }
    for (int i = 0; i < T; i++){
        int count = 0;
        if (K[i] > 0){
            bool bad = false;
            for (int j = 0; j < N[i]; j++){
                if (grids[i][0][j] == 'H' || grids[i][j][N[i] - 1] == 'H'){
                    bad = true;
                }
            }
            if (bad == false){
                count++;
            }
            bad = false;
            for (int j = 0; j < N[i]; j++){
                if (grids[i][j][0] == 'H' || grids[i][N[i]-1][j] == 'H'){
                    bad = true;
                }
            }  
            if (bad == false){
                count++;
            }
        }

        if (K[i] > 1){
            //makepaths
            for (int j = 1; j < N[i] - 1; j++){
                bool bad = false;
                for (int k = 1; k <= j; k++){
                    if (grids[i][0][k] == 'H'){
                        bad = true;
                    }
                }
                for (int k = 0; k < N[i]; k++){
                    if (grids[i][k][j] == 'H'){
                        bad = true;
                    }
                }
                for (int k = j+1; k < N[i]; k++){
                    if (grids[i][N[i]-1][k] == 'H'){
                        bad = true;
                    }
                }
                if (bad == false){
                    count++;
                }
            }
            for (int j = 1; j < N[i] - 1; j++){
                bool bad = false;
                for (int k = 1; k <= j; k++){
                    if (grids[i][k][0] == 'H'){
                        bad = true;
                    }
                }
                for (int k = 0; k < N[i]; k++){
                    if (grids[i][j][k] == 'H'){
                        bad = true;
                    }
                }
                for (int k = j+1; k < N[i]; k++){
                    if (grids[i][k][N[i] - 1] == 'H'){
                        bad = true;
                    }
                }
                if (bad == false){
                    count++;
                }
            }
        }
        if (K[i] == 3){
            //first
            for (int j = 1; j < N[i] - 1; j++){
                for (int k = 1; k < N[i] - 1; k++){
                    bool bad = false;
                    for (int l = 1; l <= j; l++){
                        if (grids[i][l][0] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = 1; l <= k; l++){
                        if (grids[i][j][l] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = j+1; l < N[i]; l++){
                        if (grids[i][l][k] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = k+1; l < N[i]; l++){
                        if (grids[i][N[i] - 1][l] == 'H'){
                            bad = true;
                        }
                    }
                    if (bad == false){
                        count++;
                    }
                }
            }
            for (int j = 1; j < N[i] - 1; j++){
                for (int k = 1; k < N[i] - 1; k++){
                    bool bad = false;
                    for (int l = 1; l <= j; l++){
                        if (grids[i][0][l] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = 1; l <= k; l++){
                        if (grids[i][l][j] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = j+1; l < N[i]; l++){
                        if (grids[i][k][l] == 'H'){
                            bad = true;
                        }
                    }
                    for (int l = k+1; l < N[i]; l++){
                        if (grids[i][l][N[i] - 1] == 'H'){
                            bad = true;
                        }
                    }
                    if (bad == false){
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
}