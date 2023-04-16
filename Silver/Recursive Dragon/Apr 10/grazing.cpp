#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

map<int,pair<int,int> >mp;
ll dist(pair<int,int>a,pair<int,int>b){
	return 1ll*(a.first-b.first)*(a.first-b.first)+1ll*(a.second-b.second)*(a.second-b.second);
}
int m,n;
struct node {
	int x,y,t;
}a[100005];
int main(){
	cin >>n >> m;;
	for(int i=1;i<=m;i++){
		int x, y, t; cin >> x >> y >> t;
		mp[t].first=x,mp[t].second=y;
		a[i].x=x,a[i].y=y,a[i].t=t;
	}
	sort(a+1,a+m+1,[](node a,node b){
		return a.t<b.t;
	});
	for(int i=1;i<m;i++)if(dist(make_pair(a[i].x,a[i].y),make_pair(a[i+1].x,a[i+1].y))>1ll*(a[i+1].t-a[i].t)*(a[i+1].t-a[i].t)){
		cout<<n<<'\n';
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x, y, t;
        cin >> x >> y >> t;
		auto it=mp.lower_bound(t);
		bool fl=0;
		if(it!=mp.end()){
			if(dist(it->second,make_pair(x,y))>1ll*(it->first-t)*(it->first-t))fl=1;
		}
		it=mp.upper_bound(t);
		if(it!=mp.begin()){
			it=prev(it);
			if(dist(it->second,make_pair(x,y))>1ll*(t-it->first)*(t-it->first))fl=1;
		}
		ans+=fl;
	}
	cout<<ans<<'\n';
	return 0;
}