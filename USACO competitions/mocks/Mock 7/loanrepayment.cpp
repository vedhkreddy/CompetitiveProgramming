#include <iostream>
#include <fstream>
using namespace std;
#define ll long long


bool works(ll x, ll n, ll k, ll m){
    ll g = 0;
    while(g < n && k > 0){
        ll y = (n - g)/x;
        if (y < m){
            ll left = (n - g + m - 1) / m;
            return (k >= left);
        }
        ll curdays = (n - x*y - g) / y + 1;
        curdays = min(curdays, k);
        g += y * curdays;
        k -= curdays;
    }
    return g >= n;
}

int main(){
    ifstream fin("loan.in");
    ofstream fout("loan.out");
    ll n, k, m;
    fin >> n >> k >> m;
    ll lo = 1;
    ll hi = 1000000000000;
    while (lo < hi){
        ll mid = (lo + hi + 1) / 2;
        if (works(mid, n, k, m)){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    fout << lo;
}