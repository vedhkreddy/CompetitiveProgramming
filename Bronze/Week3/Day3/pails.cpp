#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y, m;
    fin >> x >> y >> m;
    int bigcount = 0;
    for(int i = 0; i <= floor(m/y); i++){
        cout << i;
        int count = m;
        count -= (m - ((i) * y)) % x;
        if (count > bigcount){
            bigcount = count;
        }
    }
    fout << bigcount;
}