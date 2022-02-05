#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int n, q;
    fin >> n >> q;
    int breeds[n];
    int queries[q][2];
    int holsteins[n+1];
    int guernseys[n+1];
    int jerseys[n+1];
    int a = 0;
    int b = 0;
    int c = 0;
    holsteins[0] = a;
    guernseys[0] = b;
    jerseys[0] = c;
    for (int i = 0; i < n; i++){
        fin >> breeds[i];
        if (breeds[i] == 1){
            a++;
        }
        else if(breeds[i] == 2){
            b++;
        }
        else{
            c++;
        }
        holsteins[i+1] = a;
        guernseys[i+1] = b;
        jerseys[i+1] = c;
    }
    for (int i = 0; i < q; i++){
        fin >> queries[i][0];
        fin >> queries[i][1];
    }
    for (int i = 0; i < q; i++){
        int a = queries[i][0] - 1;
        int b = queries[i][1];
        fout << holsteins[b] - holsteins[a] << " " << guernseys[b] - guernseys[a] << " " << jerseys[b] - jerseys[a] << endl;
    }
}