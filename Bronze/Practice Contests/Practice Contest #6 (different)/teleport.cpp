#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=807
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    if (c > d){
        int tmp = c;
        c = d;
        d = tmp;
    }
    if (a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    fout << min(b - a, abs(c - a) + abs (b - d));
}