#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=663
    ifstream fin("square.in");
    ofstream fout("square.out");
    pair<pair<int, int>, pair<int, int>> first;
    pair<pair<int, int>, pair<int, int>> second;
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    first.first.first = a;
    first.first.second = b;
    first.second.first = c;
    first.second.second = d;
    int x, y, z, v;
    fin >> x >> y >> z >> v;
    second.first.first = x;
    second.first.second = y;
    second.second.first = z;
    second.second.second = v;
    int xminmax = (max({second.first.first, second.second.first, first.first.first, first.second.first}) - min({second.first.first, second.second.first, first.first.first, first.second.first}));
    int yminmax = (max({second.second.second, second.first.second, first.first.second, first.second.second}) - min({second.second.second, second.first.second, first.first.second, first.second.second}));
    if(xminmax >= yminmax){
        fout << pow(xminmax, 2);
    }
    else{
        fout << pow(yminmax, 2);
    }
}