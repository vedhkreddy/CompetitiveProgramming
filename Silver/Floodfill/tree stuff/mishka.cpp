#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long p1 = 0;
    long long p2 = n-1;
    vector<long long> v;
    for (long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    long long x = 0;
    int encapsuled = 0;
    while (encapsuled != n){
        if (v[p1] <= k){
            x++;
            p1++;
            encapsuled++;
        }
        else if (v[p2] <= k ){
            x++;
            p2--;
            encapsuled++;
        }
        else{
            break;
        }
    }
    cout << x << endl;
}