#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int main(){
    ll n, k, l;
    cin >> n >> k >> l;
    ll publications[n];
    for (ll i = 0; i < n; i++){
        cin >> publications[i];
    }
    sort(publications, publications+n, greater<int>());
    
    ll upper = n;
    ll lower = 0;

    while (upper > lower){
        ll mid = (upper + lower + 1) / 2;
        ll needed = 0;
        ll zero = 0;
        for (ll j = 0; j < mid; j++){
            needed += max(zero, mid-publications[j]);
        }
        if (needed <= k * l && publications[mid-1] + k >= mid){
            lower = mid;
        }
        else{
            upper = mid-1;
        }
    }
    cout << upper;
}
