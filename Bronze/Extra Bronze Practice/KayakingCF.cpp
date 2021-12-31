#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    //ifstream cin("this.in");
    int n;
    cin >> n;
    n *= 2;
    int list[n];
    for (int i = 0; i < n; i++){
        cin >> list[i];
    }
    sort(list, list + n);
    int min = 10000000;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int instability = 0;
            if (i == j){
                continue;
            }
            int indexlist[n-2];
            int z = 0;
            for (int b = 0; b < n; b++){
                if (b != j && b != i){
                    indexlist[z] = b;
                    z++;
                }
            }

            for (int b = 0; b < n-2; b++){
                instability += (list[indexlist[b + 1]] - list[indexlist[b]]);
                b++;
            }

            if (instability < min){
                min = instability;
            }
        }
    }
    cout << min;
}