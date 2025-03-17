#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        int totalsum = 0;
        for (int i = 0; i < n; i++){
            int a; cin >> a; v.push_back(a);
            totalsum += a;
        }
        int searchsize = n/2 + 1;
        int min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < searchsize; i++){
            sum += v[i];
        }
        //cout << sum << endl;
        int l = 0; int r = searchsize - 1;
        min = sum;
        while(r < n){
            sum -= v[l];
            l++; r++;
            if (r == n){
                break;
            }
            sum += v[r];
            if (sum < min){
                min = sum;
            }
        }
        cout << min << " " << totalsum - min << endl;
    }
}