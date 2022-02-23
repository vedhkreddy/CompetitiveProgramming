#include <iostream>
#include <fstream>
using namespace std;

long long ids[50000];
int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        ids[i+1] = ids[i] + a;
    }
    int maxlength = 0;

    for (int i = 0; i < n - maxlength; i++){
        for (int j = i + maxlength; j < n+1; j++){
            long long sum = ids[j] - ids[i-1];
            if (sum % 7 == 0){
                if (j - i + 1 > maxlength){
                    maxlength = j - i + 1;
                }
            }
        }
    }

    fout << maxlength;
}