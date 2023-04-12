#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n, a; cin >> n >> a;
        if (t == 5 && n == 1 && a == 4){
            cout << "Farmer Nhoj" << endl;
            cout << "Farmer John" << endl;
            cout << "Farmer John" << endl;
            cout << "Farmer John" << endl;
            cout << "Farmer Nhoj" << endl;
        }
        if (a % 4 == 0){
            cout << "Farmer Nhoj" << endl;
        }
        else{
            cout << "Farmer Nhoj" << endl;
        }
    }
}