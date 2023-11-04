#include<bits/stdc++.h>
using namespace std;
const int maxm = (int)1e5 + 10;
int siz[maxm];
vector<int> pos[maxm];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k; cin >> n >> m >> k;
    int rg = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d",&x);
        pos[x].push_back(i);
    }
    for (int i = 1; i < maxm; i++) {
        siz[i] = size(pos[i]);
        rg = max(rg,siz[i]);
    }
    rg++;
    int lf = 0;
    while(lf < rg - 1) {
        int mm = (lf + rg) >> 1;
        bool ok = false;
        for (int i = 1; i < maxm; i++) if (siz[i] >= mm) {
            for (int j = 0; j < siz[i] - mm + 1; j++) {
                if (pos[i][j + mm - 1] - pos[i][j] + 1 - mm <= k) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) {
            lf = mm;
        } else {
            rg = mm;
        }
    }
    cout << lf << endl;
    return 0;
}