#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Comparefirst {
    bool operator()(const pair<int, int>&a, const pair<int, int> &b){
        return ((a.first - a.second) > (b.first - b.second));
    }
};

struct Comparesecond {
    bool operator()(const pair<int, int>&a, const pair<int, int> &b){
        return ((a.second - a.first) > (b.second - b.first));
    }
};

int firstbenefit(pair<int, int> p){
    return p.first - p.second;
}

int secondbenefit(pair<int, int> p){
    return p.second - p.first;
}

int32_t main(){
    //ifstream cin("inp.in");
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a; vector<int> b;
        for (int i = 0; i < n; i++){
            int x; cin >> x; a.push_back(x);
        }
        for (int i = 0; i < n; i++){
            int x; cin >> x; b.push_back(x);
        }
        int maxres = INT_MIN;;
        for (int i = 1; i < n; i++){
            int firstp = 0;
            int secondp = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, Comparefirst> first;
            priority_queue<pair<int ,int>, vector<pair<int, int>>, Comparesecond> second;
            for (int j = 0; j < i; j++){
                first.push(make_pair(a[j], b[j]));
            }
            for (int j = i; j < n; j++){
                second.push(make_pair(a[j], b[j]));
            }
            while(true){
                if (firstbenefit(second.top()) > firstbenefit(first.top())){
                    pair<int, int> x = second.top(); second.pop();
                    pair<int, int> y = first.top(); first.pop();
                    //cout << y.first << " " << y.second << x.first << " " << x.second << endl;
                    first.push(x); second.push(y);
                }
                else{
                    break;
                }
            }
            int maxsecond = -1 * INT_MAX;
            int maxfirst = -1 * INT_MAX;
            while(first.size() != 0){
                firstp += first.top().first;
                if (first.top().second > maxsecond){
                    maxsecond = first.top().second;
                }
                first.pop();
            }
            while(second.size() != 0){
                secondp += second.top().second;
                if (second.top().first > maxfirst){
                    maxfirst = second.top().first;
                }
                second.pop();
            }
            int res = firstp + secondp;
            if (maxsecond > maxfirst){
                res += maxsecond;
            }
            else{
                res += maxfirst;
            }
            if (res > maxres){
                maxres = res;
            }
        }
        if (a.size() == 1 && b.size() == 1){
            cout << a[0] + b[0] << endl;
        }
        else{
            cout << maxres << endl;
        }
    }
}       