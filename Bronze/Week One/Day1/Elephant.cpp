#include<iostream>
#include<cmath>
using namespace std;

int main(){
    //https://codeforces.com/problemset/problem/617/A
    int a;
    cin >> a;
    int moves = 0;
    if (a % 5 == 0){
        cout << a/5;
    }
    else{
        cout << floor(a/5) + 1 << endl;
    }
}