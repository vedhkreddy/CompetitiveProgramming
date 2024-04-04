#include <bits/stdc++.h>
using namespace std;

/*
Observations: we cal calculate optimal for 2 courses (x, x+1)
    2: single iteration greedy doesnt work if a really good course comes up
    3: buy the next course asap
    4: 

Method 1: iteration
    calculate for every day if we stayed there, what is the min days
    we automatically go to the next one and calculate
    take the min of everything

1 3 10 11
1 2 7

*/

int main(){
    ifstream cin("codeforces.in");
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<int> a; vector<int> b;
        for(int i = 0; i < n; i++){
            int x; cin >> x; a.push_back(x);
        }
        for(int i = 0; i < n-1; i++){
            int s; cin >> s; b.push_back(s);
        }
        vector<int> days;
        int balance = 0;
        for(int i = 0; i < n; i++){
            int tg = c - balance;
            int x = ceil(float(tg) / float(a[i]));
            days.push_back(x);
            //mathematically find how many days until advance
            if (i != n-1){
                if (b[i] <= balance){
                    balance -= b[i];
                }
                else{
                    int adv = ceil(float(b[i] - balance) / float(a[i]));
                    balance += (adv * a[i]);
                    balance -= b[i];
                }
            }
        }    
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if (res < days[i]){
                res = days[i];
                //cout << days[i] << endl;
            }
        }
        cout << res << endl;
    }
}