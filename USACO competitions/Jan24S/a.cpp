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

const int mxN = 2e5+5;
int n;

/*
Observation 1: Any number that doesn't have a 0 stays the same
Observation 2: If we try updating max's, then we only have to look at zeros
Observation 3

Subproblem 1: Given a list of mins, how can we update quickly
    updating quickly doesn't really do much for us

Method 1: Brute Force
    for every query Q, iterate through the list ai to aj and figure out what number to choose
    O(n^2)
        n queries

Method 2: Optimized Black Box w check
    1) For every number that's a 0 and doesn't have a query, replace with 1
    2) for every query:
        check(max) in o(1)
        add lex min
        update check

    for this check function to work
        precomp in o(n)
        update in o(logn) or o(1)

Method 3: one iteration
    1) iterate and store max for each subset
    2) if cur is zero, then
        if(has statement)
            set it greater than the max
            chekc if greater than curmax
        else
            set to 1
    3) if cur isn't zero but is func
        then just go and check
            if bad output -1 return

pseudocode
    1) read in array C
    2) create map of all queries q
        reversed btw
    3) for 1, n
        if cur is zero
            if cur has statements
                check if true or nah
                update
        if cur has statements
            check for stored max and last max
            if not then output -1

*/

void solve(){
    int n, q, c; cin >> n >> q >> c;
    vi scores;
    forr(i, 0, n){
        int a; cin >> a;
        scores.pb(a);
    }
    unordered_map<int, int> quer;
    forr(i, 0, q){
        int a, b; cin >> a >> b;
        b--; a--;
        if (quer.count(b) == 0)
            quer[b] = max(quer[b], a);
        else{
            quer[b] = a;
        }
    }
    //cout << quer[1] << endl;
    vector<int> bigs;
    if (scores[0] == 0){
        scores[0] = 1;
        bigs.pb(1);
    }
    else{
        bigs.pb(scores[0]);
    }
    vector<int> change;
    forr(i, 1, n){
        if (scores[i] == 0){
            if (quer.count(i) == 0){
                scores[i] = 1;
            }   
            else{
                scores[i] = bigs[quer[i]] + 1;
            }
            change.pb(true);
        }
        else{change.pb(false);}
        if (scores[i] > bigs[i-1])
            bigs.pb(scores[i]);
        else{ 
            bigs.pb(bigs[i-1]);
        }
        if (quer.count(i) != 0){
            if (bigs[quer[i]] < bigs[i-1]){
                if (change[quer[i]] == true){
                    
                }
                cout << "-1" << endl;
                return;
            }
        }
        if (scores[i] > c){
            cout << "-1" << endl;
            return;
        }
        cout << scores[i] << " " << bigs[i] << " " << endl;
    }
    forr(i, 0, n){
        cout << scores[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("a.in", "r", stdin);    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}