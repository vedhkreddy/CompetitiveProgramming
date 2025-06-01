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
#define FOR(i,b) for (int i = 0; i < (b); i++)
#define ford(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define trav(a,x) for (auto& a: x)
const ll MOD = 1e9+7;

const int mxN = 2e5+5;
map<int, int> weights;
map<int, int> inout;
vi present;
map<int, pair<int, int>> dir;
map<int, int> here;
int n; int a; int b;

int res = 0;

void dfs(int node, int prev, int carry){
    //cout << node << " " << prev << " " << carry << endl;
    here[node] = 1;
    int child1 = dir[node].f;
    int child2 = dir[node].s;
    if (prev == -2){
        dfs(child1, node, weights[node]);
        return;
    }
    else if (weights[node] <= carry){
        res += weights[node];
        weights[node] = 0;
    }
    else {
        weights[node] -= carry;
        res += carry;
    }
    if (child1 != prev && child1 != -1 && !here.count(child1)) dfs(child1, node, weights[node]);
    if (child2 != prev && child2 != -1 && !here.count(child2)) dfs(child2, node, weights[node]);
}

void add(int x, int y){
    if (!dir.count(y)) return;
    if (x == y) return;
    if (dir[x].f == -1) {dir[x].f = y; return;}
    dir[x].s = y;
}

int main() {
    ifstream cin("x.in");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    FOR(i, n){
        int x; int y; cin >> x >> y; 
        weights[y] = x; present.pb(y);
        if (!dir.count(y)) dir[y] = {-1, -1};
    }
    FOR(i, n){
        add(present[i], a-present[i]);
        add(present[i], b-present[i]);
    }
    FOR(i, n) //cout << present[i] << " " << weights[present[i]] << endl;;
    FOR(i, n){
        if (dir[present[i]].f != -1 && dir[present[i]].s == -1 && !here.count(present[i])) dfs(present[i], -2, weights[present[i]]);
    }
    if (a % 2 == 0){
        if (weights.count(a/2)) res += weights[a/2] / 2;
    }
    if (b % 2 == 0){
        if (weights.count(b/2)) res += weights[b/2] / 2;
    }
    cout << res << endl;
}