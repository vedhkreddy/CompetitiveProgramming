#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
#define f first
#define s second
#define pb push_back
#define FOR(i,b) for (int i = 0; i < (b); i++)

/*
    obviously, we can calculate the expected enjoyment for starting each run
    without ci, we can find the maximum value with an array
        dp[i] = max
        i = node, max = max node on that slope
        from there, we add each node as a pair<max, enjoyment>, sort by max and enjoyment
        and then binary search on the max for each one
    with ci, we can ignore a few things
        dp[i][j] = jmax
            i = node, j = j'th max on that slope
            how do we calculate this?
        within the dfs, it's hard to calculate it
    we can bfs 10 times
        each time we try storing a different level of maxes
        if we know the previous max, we just have to find the max thats less
            main problem: duplicates
        dp[i][j] = max <= dp[i][j-1]
            how to  handle duplicates?
            we can store how many times we've seen a certain one, and then fill them all in at that certain time
                in doing so, we don't actually have to consider duplicates if it's already filled in
        how to fill in dp array in the first place?
            storing the max <= current isn't so easy because we can't compare it every step of the way
            we know the 2nd max from all the previous nodes, we just have to check if this current node > past 2nd max
            and see if the thing isn't alr filled in and if it works for the condition
    
*/
const int mxn = 100005;
vector<int> adj[mxn];
int difficulty[mxn];
ll enjoyment[mxn];
bool visited[mxn];
int n; int m;
ll dp[mxn][11];
int cur = 0;
int depth[mxn];
ll totalenjoyment[mxn];

void dfsmax(int node, int parent){
    enjoyment[node] += enjoyment[parent];
    visited[node] = true;
    if (parent == -1){
        dp[node][1] = difficulty[node];
        depth[node] = 0;
    }
    else if (difficulty[node] > dp[parent][1])
        dp[node][1] = difficulty[node];
    else
        dp[node][1] = dp[parent][1];
    if (parent != -1)
        depth[node] = depth[parent] + 1;
    for (int i : adj[node]){
        if (!visited[i])
            dfsmax(i, node);
    }
}

void clearvisited(){
    FOR(i, mxn) visited[i] = 0;
}
//if eveyr element is unique, we have to check if the difficulty of the current on is already captured, because if its not captured then its easy to check if its greater than that of th eprevious and then set it
//the problem arises when there are duplicates, because then we have to chekc how many previous ones
    //we'll know going backwards, how many times this number has been the maximum
        //we can't always check this because 

void dfsfill1(int node, pqi p){
    p.push(difficulty[node]);
    while (p.size() > cur) p.pop();
    if (p.size() < cur) dp[node][cur] = 0;
    else dp[node][cur] = p.top();
    for (int x : adj[node]) dfsfill1(x, p);
}

int main() {
    //ifstream cin("x.in");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    FOR(i, n-1){
        int p; int d; int e; 
        cin >> p >> d >> e;
        //cout << p << " " <<d << " " << e << endl;
        adj[p].pb(i+2);
        difficulty[i+2] = d;
        enjoyment[i+2] = e;
    }
    
    dfsmax(1, -1);
    //now we have to fill in the rest of the dp array
    for (int i = 1; i < 11; i++){
        cur = i;
        pqi p;
        dfsfill1(1, p);
    }

    vector<pair<int, ll>> final[11];
    for (int j = 1; j <= 10; j++) {
        for (int i = 1; i <= n; i++) { 
            final[j].push_back({dp[i][j], enjoyment[i]});
        }
        sort(final[j].begin(), final[j].end(), [](const pair<int, ll> &a, const pair<int, ll> &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
    }
    vector<pair<int, ll>> greatest[11];
    
    for (int j = 1; j <= 10; j++) {
        int curmax = 0;
        for (const auto& p : final[j]) {
            if (p.s > curmax){
                curmax = p.s;
            }
            greatest[j].push_back({p.f, curmax});
        }
    }
    //now, for each query, binary search based on greatest and find the first height less than the current, then output the answer
    int m; cin >> m;
    FOR(i, m){
        int h; int c; cin >> h >> c; c++;
        //query on greatest[c] for the first height less than h and output that answer
        bool good = false;
        for (int l = 0; l < greatest[c].size() - 1; l++){
            if (greatest[c][l+1].f > h){
                cout << greatest[c][l].s << endl;
                good  = true;
                continue;
            }
        }
        if(!good) cout << greatest[c][greatest[c].size() - 1].s << endl;;
    }
}