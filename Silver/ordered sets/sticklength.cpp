#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    sort(array, array + n);
    int med = array[n/2];
    ll sol = 0;
    for (int i = 0; i < n; i++){
        sol += abs(med - array[i]);
    }
    cout << sol;
}