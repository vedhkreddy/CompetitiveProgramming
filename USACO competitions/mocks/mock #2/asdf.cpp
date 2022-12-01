#include <iostream>
#include <fstream>
using namespace std;

int grid[5];

int bsearch(int x){
    int a = 0, b = 4;
    while (a <= b) {
        int k = (a+b)/2;
        if (grid[k] == x) {   
            return k; 
        }
        if (grid[k] > x) b = k-1;
        else a = k+1;
    }
    return 0;
}

int main(){
    for (int i = 0; i < 4; i++){
        cin >> grid[i];
    }
    cout << bsearch(3);
}