#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        vector<int> p;
        for (int i = 0; i < v.size(); i++){
            if (v[i] % 4 == 0){
                p.push_back((v[i]/4) + 1);
            }
            else{
                p.push_back(floor(float((v[i]/4))));
            }
        }
        int min = INT32_MAX;
        int index;
        for (int i = 0; i < n; i++){
            if (p[i] < min){
                min = p[i];
                index = i;
            }
        }
        if (v[index] % 4 == 0){
            cout << "Farmer Nhoj" << endl;
        }
        else{
            cout << "Farmer John" << endl;
        }
    }
}