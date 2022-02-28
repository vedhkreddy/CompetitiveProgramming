#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int needed[501];
int solutions[501];
int frequency[501];
int main(){
    ifstream cin("this.in");
    int n;
    cin >> n;
    int preferences[n][n];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> preferences[i][j];
        }
    }
    vector<vector<int>> vv;
    for (int i = 0; i < n; i++){
        vector<int> v;
        for (int j = 0; j < n; j++){
            if (preferences[i][j] == i+1){
                v.push_back(preferences[i][j]);
                break;
            }
            v.push_back(preferences[i][j]);
        }
        vv.push_back(v);
    }

    //check for end
    for (int i = 0; i < n; i++){
        frequency[preferences[i][n-1]] += 1;
    }
    for (int i = 0; i < n; i++){
        if (frequency[i+1] >= n-1){
            bool bad = false;
            for (int j = 0; j < n; j++){
                if (preferences[j][n-1] != i+1 && j != n-1){
                    bad = true;
                    break;
                }
            }
            if (bad == false){
                solutions[i+1] = i+1;
                needed[i+1] = 1;
            }
        }
    }

    //check for preferred first
    for(vector<int> v : vv){
        if (v.size() == 1){
            solutions[v[0]] = v[0];
            needed[v[0]] = 1;
        }
    }

    //keep checking for doing stuff
    bool whendone = true;
    while (whendone == true){
        whendone = false;
        int cur = 0;
        for (vector<int> v : vv){
            for (int j : v){
                if (needed[j] == 0){
                    if (j == cur+1){
                        whendone = true;
                        needed[j] = 1;
                        solutions[j] = j;
                    }
                    break;
                }
            }
            cur++;
        }
    }

    for (int i = 0; i < n; i++){
        if (solutions[i+1] != 0){
            cout << solutions[i+1] << endl;
        }
        else{
            for (int j : vv[i]){
                if (needed[j] == 0){
                    cout << j << endl;
                    break;
                }
            }
        }
    }
}