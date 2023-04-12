#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    int n, d;
	cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int jumps = 0;
    for (int i = 0; i < n; i++){
        int x = min(i + d, n-1);
        int ind = -1;
        for (int j = x; j > i; j--){
            if (arr[j] == 1){
                ind = j;
            }
        }
        if (ind == -1){
            cout << "-1" << endl;
            return 0;
        }
        jumps++;
        if (ind == n-1){
            cout << jumps << endl;
            return 0;
        }
        else{
            i = ind;
        }
    }
}