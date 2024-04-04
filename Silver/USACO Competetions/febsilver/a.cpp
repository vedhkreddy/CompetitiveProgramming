#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define forr(i,a,b) for (int i = (a); i < (b); i++)
#define ford(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define trav(a,x) for (auto& a: x)
const ll MOD = 1e9+7;

const int mxN = 3e5+5;
int seq[mxN];
map<int, int> m;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> choices;
    int tot = n;
    forr(i, 0, m){
        vi v;
        forr(j, 0, k){
            int a; cin >> a;
            v.pb(a);
        }
        choices.pb(v);
    }
    forr(i, 0, m){
        int bigodd = -INT_MAX;
        forr(j, 0, k){
            if (choices[i][j] % 2 == 1){
                if (choices[i][j] > bigodd){
                    bigodd = choices[i][j];
                }
            }
        }
        tot -= bigodd;
        if (tot <= 0){
            //work backwards until we get, if we reach a node store the delta
            int upd = 0;
            ford(j, i+1, 0){
                int lowesteven = INT_MAX;
                int lowestodd = INT_MAX;
                int highestodd = -INT_MAX;
                forr(x, 0, k){
                    if(choices[j][x] % 2 == 0){
                        if (choices[j][x] < lowesteven) lowesteven = choices[j][x];
                    }
                    else{
                        if (choices[j][x] < lowestodd) lowestodd = choices[j][x];
                        if (choices[j][x] > highestodd) highestodd = choices[j][x];
                    }
                }
                
                //handle casework
                if (lowestodd == INT_MAX){
                    //cout << "xxx";
                }
                else{
                    if (lowesteven == INT_MAX){
                        upd += lowestodd + highestodd;
                    }
                    else if (lowesteven > lowestodd){
                        upd += (lowesteven - lowestodd);
                    }
                    //cout << "here" << endl;
                    seq[j] = 1;
                }
                if (tot + upd > 0){
                    tot += upd;
                    break;
                }
            }
            if (tot + upd <= 0){
                cout << "-1" << endl;
                return;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if (i == m-1){
            if (seq[i] == 0){
                cout << "Even";
            }
            else{
                cout << "Odd";
            }
            continue;
        }
        if (seq[i] == 0){
            cout << "Even" << " ";
        }
        else{
            cout << "Odd" << " ";
        }
        seq[i] = 0;
    }
}

/*

iterate through as normal, setting everything to even
if it goes below zero
    optimize()
    we go backwards, optimizing each node until we get above zero for curnode
    as we go backwards, if we have already optimized a certain range of nodes, we can skip it
    we can skip it through storing some variables
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("codeforces.in", "r", stdin);
    int t; cin >> t;
    while (t != 0){
        solve();
        if(t != 1) cout << endl;
        t--;
    }
}