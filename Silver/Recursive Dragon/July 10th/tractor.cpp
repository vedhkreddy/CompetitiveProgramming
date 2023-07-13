#include <bits/stdc++.h>
typedef long long int ll;
#define INF (1e9 + 7)
#define INF2 (998244353)
#define N (ll)1e5+5
using namespace std;

int a[501][501], p[260000], s[260000], n;

vector<pair<int, pair<int, int>>> v;

int get(int a){
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    int x = get(a), y = get(b);
    if(x==y)return;
    if(s[x] < s[y]){
        swap(x, y);
    }
    p[y] = x;
    s[x] += s[y];
}

void solve(){
    cin >> n;
    for(int i=1; i<260000; i++){
        s[i] = 1;
        p[i] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i > 1){
                v.push_back({abs(a[i][j] - a[i-1][j]), {i * n + j, (i-1) * n + j}});
            }
            if(j > 1){
                v.push_back({abs(a[i][j] - a[i][j-1]), {i * n + j, i * n + j - 1}});
            }
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        unite(v[i].second.first, v[i].second.second);
        if(s[get(v[i].second.first)] >= (n * n + 1)/2){
            cout<<v[i].first;
            return;
        }
    }
}   

int main(){ 
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int T = 1;
    solve();
}
