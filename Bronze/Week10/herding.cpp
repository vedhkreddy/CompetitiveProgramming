#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
        //http://usaco.org/index.php?page=viewproblem2&cpid=915
        ifstream fin("herding.in");
        ofstream fout("herding.out");
        int cows[3];
        for(int i = 0; i < 3; i++){
            fin >> cows[i];
        }
        sort(begin(cows), end(cows));
        //check if already in consecutive positions
        if (cows[1] - cows[0] == 1 && cows[2] - cows[1] == 1){
            fout << 0 << endl;
            fout << 0;
            return 0;
        }
        //find the mininum
        if (cows[1] - cows[0] == 2 || cows[2] - cows[1] == 2){
            fout << 1 << endl;
        }
        else{
            fout << 2 << endl;
        }
        //find the maximum
        int first = cows[1] - cows[0];
        int second = cows[2] - cows[1];
        int maxinterval = max(first, second);
        fout << maxinterval -  1;
}