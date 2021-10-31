#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=988
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    int N;
    fin >> N;
    vector<int> permb;
    for(int i = 0; i < N - 1; i++){
        int a;
        fin >> a;
        permb.push_back(a);
    }
    for(int i = 1; i < permb[1]; i++){
        vector<int> perma;
        perma.push_back(i);
        int curcount = i;
        for(int j : permb){
            perma.push_back(j - curcount);
            curcount = j - curcount;
        }
        bool bad = false;
        set<int> s;
        for(int j : perma){
            if (j <= 0){
                bad = true;
            }
            s.insert(j);
        }
        if (perma.size() != s.size()){
            bad = true;
        }
        if (bad == false){
            for (int i = 0; i < N; i++){
                if (i == N-1){
                    fout << perma[i];
                }
                else{
                    fout << perma[i] << " ";
                }
            }
            return 0;
        }
    }
}