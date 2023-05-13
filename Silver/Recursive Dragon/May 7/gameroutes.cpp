#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+1;
const ll MOD = 1e9+7;

int N, M, cnt, in[maxN];
ll dp[maxN];
vector<int> graph[maxN];
queue<int> sequence;

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            sequence.push(i);

    dp[1] = 1;
    while(!sequence.empty()){
        int u = sequence.front(); sequence.pop();
        for(int v : graph[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            in[v]--;
            if(in[v] == 0)
                sequence.push(v);
        }
    }

    cout << dp[N];
}