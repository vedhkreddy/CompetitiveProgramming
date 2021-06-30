#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=567
    //fixed segfault
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a, b, c, d;
    int painted = 0;
    fin >> a >> b >> c >> d;
    bool fence[101];
    for (int i = 0; i < 101; i++){
        fence[i] = false;
    }
    for(int i = a; i < b; i++){
        fence[i] = true;
    }
    for(int i = c; i < d; i++){
        fence[i] = true;
    }
    for(bool b: fence){
        if(b == true){
            painted++;
        }
    }
    fout << painted;
}