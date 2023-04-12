#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long t; cin >> t;
    for (long long i = 0; i < t ; i++){
        long long n; cin >> n;
        vector<long long> v;
        for (long long j = 0; j < n; j++){
            long long a; cin >> a; 
            v.push_back(a);
        }
        sort(v.begin(), v.end(), greater<long long>());
        long long total = v[0];
        for (long long j = 1; j < v.size(); j++){
            if (v[j] != 1){
                total *= v[j];
                v.push_back(1);
            }
            else{
                total++;
            }
        }
        cout << total * 2022 << endl;
    }
}