#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
typedef pair<int,int> ii;
 
queue<int> q;
vector<int> vec[200003];
vector<int> ans, seq;
int occ[200003];
 
bool visited[200003];
 
bool comp(int a, int b)
{
	return occ[a] < occ[b];
}
 
int32_t main()
{
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
 
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		seq.push_back(x);
		occ[x] = i;
	}
 
	for(int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end(), comp);
 
	q.push(1);
	visited[1] = 1;
	ans.push_back(1);
 
	while(q.size())
	{
		int u = q.front(); q.pop();
		for(int v : vec[u])
		{
			if(!visited[v])
			{
				q.push(v);
				visited[v] = 1;
				ans.push_back(v);
			}
		}
	}
	if(ans == seq){
        cout << "Yes" << endl;
    }
	else{
        cout << "No" << endl;
    }
 
}