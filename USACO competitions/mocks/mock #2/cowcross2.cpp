#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");
    int n, k, b;
    cin >> n >> k >> b;
    int vals[n+1];
    for (int i = 0; i < n; i++){
        vals[i] = 0;
    }
    for (int i = 0; i < b; i++){
        int num;
        cin >> num;
        vals[num-1] = 1;
    }
    int minrepair = 100000;
    int currepair = 0;
    int i = 0; int j = k-1;
    for (int l = 0; l < k; l++){
        if (vals[l] == 1){
            currepair++;
        }
    }
    while(j < n){
        if (currepair < minrepair){
            minrepair = currepair;
        }
        if (vals[i] == 1){
            currepair--;
        }
        i++;
        j++;
        if (vals[j] == 1){
            currepair++;
        }
    }
    cout << minrepair;
}