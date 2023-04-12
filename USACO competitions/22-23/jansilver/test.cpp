#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n; cin >> n;
    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
        }
        else{
            n *= 3;
            n++;
        }
        cout << n << " ";
    }
    cout << endl;
}   