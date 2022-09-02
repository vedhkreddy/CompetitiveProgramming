#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    n*=2;
    n--;
    for (int i = 1; i <= n; i+=2){
        for (int j = 0; j < (n - i)/2; j++){
            cout << ".";
        }
        for(int j = 0; j < i; j++){
            cout << "#";
        }
        for (int j = 0; j < (n - i)/2; j++){
            cout << ".";
        }
        cout << endl;
    }
    for (int i = n-2; i >= 1; i -= 2){
        for (int j = 0; j < (n - i)/2; j++){
            cout << ".";
        }
        for(int j = 0; j < i; j++){
            cout << "#";
        }
        for (int j = 0; j < (n - i)/2; j++){
            cout << ".";
        }
        cout << endl;
    }
}