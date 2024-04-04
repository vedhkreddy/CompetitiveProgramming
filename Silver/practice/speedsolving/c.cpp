#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin >> t;
    while (t--){
        long long n; cin >> n;
        vector<long long> v;
        long long sum = 0;
        for(long long i = 0; i < n; i++){
            long long a; cin >> a;
            v.push_back(a);
            sum += a;
        }
        long long sr = sqrt(sum);
        if (sr * sr == sum){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}