
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 5;
const ll ZER = 0;
const ll ONE = 1;
const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

ll conver(char c) {
    ll ret;
    if (c >= 'a' && c <= 'z') {
        ret = c - 'a';
    } else {
        ret = c - 'A';
        ret += 26;
    }
    
    return ret;
}
void solve(ll ca)
{
    string s1, s2;
    cin >> s1 >> s2;
    
    ll par[52]; 
    set<ll> checkma[52]; 
    set<ll> child[52];
    set<ll> child2[52];
    
    for (ll i = 0; i < 52; i++) {
        par[i] = -1;
    }
    for (ll i = 0; i < s1.length(); i++) {
        par[conver(s1[i])] = conver(s2[i]);
        checkma[conver(s1[i])].insert(conver(s2[i]));
        child[conver(s2[i])].insert(conver(s1[i]));
        child2[conver(s2[i])].insert(conver(s1[i]));
    }
    for (ll i = 0; i < 52; i++) {
        if (checkma[i].size() > 1) {
            cout << -1 << endl;
            return;
        }
    }

    queue<ll> bfs;
    for (ll i = 0; i < 52; i++) {
        if (child[i].size() == 0 && par[i] != -1) {
            bfs.push(i);
        }
    }
    ll ans = 0;
    while (bfs.size() > 0) {
        ll cur = bfs.front();
        bfs.pop();
        if (par[cur] == -1) {
            continue;
        }
        ans++;
        child[par[cur]].erase(cur);
        if (child[par[cur]].size() == 0) {
            bfs.push(par[cur]);
        }
    }
    vector<vector<ll>> cycles;

    bool visited[52];
    for (ll i = 0; i < 52; i++) {
        visited[i] = false;
    }
    
    for (ll i = 0; i < 52; i++) {
        if (visited[i]) {
            continue;
        }
        
        if (child[i].size() == 0) {
            continue;
        }
        
        vector<ll> tem;
        ll cur = i;
        while (child[cur].size() == 1) {
            if (!visited[cur]) {
                visited[cur] = true;
                tem.push_back(cur);
                cur = par[cur];
                if (par[cur] == -1) {
                    break;
                }
            } else {
                break;
            }
        }
        cycles.push_back(tem);
    }
    
    bool found = false;
    for (ll i = 0; i < 52; i++) {
        if (!visited[i]) {
            found = true;
            break;
        }
    }
    
    for (auto el: cycles) {
        if (el.size() == 1) {
            continue;
        }
        bool found2 = false;
        for (auto el2: el) {
            if (child2[el2].size() > 1) {
                found2 = true;
                break;
            }
        }

        if (found2) {
            ans += el.size();
        } else if (found) { 
            ans += (el.size()+1);
        } else { 
            cout << -1 << endl;
            return;
        }
    }
    
    cout << ans << endl;
    
    return;
}


int main()
{

    ll t = 1;
    cin >> t;

    ll co = 1;
    while (t--) {
        solve(co);
        ++co;
    }
}