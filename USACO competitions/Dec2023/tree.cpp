#include<bits/stdc++.h>
#define N 300005
#define inf 1e9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int f[N],val[N],ans;
vector<int> g[N];
void dfs(int u,int fa)
{
	int len=g[u].size();
	if (len==0) f[u]=1,ans++;
	else if (val[u]==1) f[u]=inf;
	for (int i=0;i<len;i++)
	{
		int v=g[u][i];
		if (v==fa) continue;
		dfs(v,u);
		if (val[u]==0) f[u]+=f[v];
		else f[u]=min(f[u],f[v]);
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>val[i];
	for (int i=2;i<=n;i++)
	{
		int fa;cin>>fa;
		g[fa].push_back(i);
	}
	dfs(1,0);
	cout<<max(ans-f[1]+1,1)<<endl;
}
 