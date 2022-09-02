#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int similar[3000];
int main(){
    string str;
    cin >> str;
    int s = str.size();
    int num = 0;
    int pot = 1;
    similar[0] = 1;
    for (int i = s-1; i >= 0; i--){
        num = (num + pot * (str[i] - '0')) % 2019;
        similar[num]++;
        pot = pot * 10 % 2019;
    }

    long long sol = 0;
    for (int i = 0; i < 3000; i++){
        sol += (similar[i]-1) * similar[i] / 2;
    }
    cout << sol;
    
}