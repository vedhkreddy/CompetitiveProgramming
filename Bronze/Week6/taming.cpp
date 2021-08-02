#include <iostream>
#include <fstream>
using namespace std;

void solve(int N, auto log){
    ifstream fin("taming.in");
    ofstream fout("taming.out");
    bool bad = false;
    for(int i = 0; i < N; i++){
        if(log[i] != -1){
            int index = 0;
            for (int j = i - log[i]; j < i; j++){
                if (log[j] != index && log[j] != -1){
                    bad = true;
                }
                log[j] = index;
                index++;
            }
        }
    }
    int min = 0;
    int plus = 0;
    for (int i = 0; i < N; i++){
        if (log[i] == 0){
            min++;
        }
        if(log[i] == -1){
            plus++;
        }
    }
    if (bad == true){
        fout << -1;
        return;
    }
    fout << min << " " << min + plus << endl;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=809
    ifstream fin("taming.in");
    ofstream fout("taming.out");
    int N;
    fin >> N;
    int log[N];
    for (int i = 0; i < N; i++){
        int a;
        fin >> a;
        log[i] = a;
    }
    log[0] = 0;
    solve(N, log);
}