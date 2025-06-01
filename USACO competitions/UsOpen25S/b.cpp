#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define FOR(i,b) for (int i = 0; i < (b); i++)

unordered_map<int, int> weights;
unordered_map<int, int> inout;
vi present;
unordered_map<int, pi> dir;
int n; int a; int b;
int visited[200005];
set<int> exists;
set<int> here;

unordered_map<int, int> idsystem;

long long res = 0;

void dfs(int node, int prev, int carry){
    //cout << node << " " << prev << " " << carry << endl;
    here.insert(node);
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
    if (child1 != prev && child1 != -1 && here.find(child1) == here.end()) dfs(child1, node, weights[node]);
    if (child2 != prev && child2 != -1 && here.find(child2) == here.end()) dfs(child2, node, weights[node]);
}

void add(int x, int y){
    if (exists.find(y) == exists.end()) return;
    if (x == y) return;
    if (dir[x].f == -1) {dir[x].f = y; return;}
    dir[x].s = y;
}

int32_t main() {
    ifstream cin("x.in");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    FOR(i, n){
        int x; int y; cin >> x >> y; 
        weights[y] = x; present.pb(y);
        if (exists.find(y) == exists.end()) dir[y] = {-1, -1};
        exists.insert(y);
    }
    FOR(i, n){
        add(present[i], a-present[i]);
        if (a != b) add(present[i], b-present[i]);
    }
    FOR(i, n) //cout << present[i] << " " << weights[present[i]] << endl;
    FOR(i, n){
        if (dir[present[i]].f != -1 && dir[present[i]].s == -1 && here.find(present[i]) == here.end() && !((a%2 == 0 && 2 * present[i] == a) || (b%2 == 0 && 2 * present[i] == b))) dfs(present[i], -2, weights[present[i]]);
    }
    if (a % 2 == 0){
        if (exists.find(a/2) != exists.end()) res += weights[a/2] / 2;
    }
    if (b % 2 == 0 && a != b){
        if (exists.find(b/2) != exists.end()) res += weights[b/2] / 2;
    }
    cout << res << endl;
}