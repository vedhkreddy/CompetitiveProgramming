#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //https://codeforces.com/problemset/problem/996/A
    int n;
    cin >> n;
    int count = 0;
    count += floor(n/100);
    count += floor((n%100) / 20);
    count += floor(((n%100) % 20) / 10);
    count += floor((((n%100) % 20) % 10) / 5);
    count += floor(((((n%100) %20 ) %10) %5));
    cout << count << endl;
}