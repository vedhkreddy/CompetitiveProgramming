#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//checks if valid combination
bool check(vector<int> bucketvalues, int cows[]){
    vector<int> cows1, cows2;
    for(int i = 0; i < 10; i++){
        cows1.push_back(cows[i]);
    }
    for(int i = 10; i < 20; i++){
        cows2.push_back(cows[i]);
    }
    for(int i = 0; i < 4; i++){
        if (i % 2 == 0){
            bool found = false;
            for(int j : cows1){
                if (j == bucketvalues[i]){
                    found = true;
                }
            }
            if (found == false){
                return false;
            }
            cows2.push_back(bucketvalues[i]);
            auto position = find(cows1.begin(), cows1.end(), bucketvalues[i]);
            if (position != cows1.end()){
                cows1.erase(position);
            }
        }
        else{
            bool found = false;
            for(int j : cows2){
                if (j == bucketvalues[i]){
                    found = true;
                }
            }
            if (found == false){
                return false;
            }
            cows1.push_back(bucketvalues[i]);
            auto position = find(cows2.begin(), cows2.end(), bucketvalues[i]);
            if (position != cows2.end()){
                cows2.erase(position);
            }
        }
    }
    return true;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=857
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    int cows[20];
    for(int i = 0; i < 20; i++){
        int a;
        fin >> a;
        cows[i] = a;
    }
    //select all combinations
    vector<vector<int>> bucketvalues;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 20; k++){
                for(int l = 0; l < 20; l++){
                    bucketvalues.push_back({cows[i], cows[j], cows[k], cows[l]});
                }
            }
        }
    }
    //make sure combinations are valid before capturing the result using a set to make result unique
    int valuesize = bucketvalues.size();
    set<int> values;
    for(int i = 0; i < valuesize; i++){
        if (check(bucketvalues[i], cows)){
            int result = bucketvalues[i][1] - bucketvalues[i][0] - bucketvalues[i][2] + bucketvalues[i][3];
            values.insert(result);
        }
    }
    fout << values.size();
}