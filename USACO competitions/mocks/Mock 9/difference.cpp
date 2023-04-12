#include<bits/stdc++.h>
using namespace std;
 
int n;
 
vector<int> a,b; 
 
int main()
{
	int t; cin>>t; while(t--)
	{
		a.clear();
		cin>>n;
		int cnt0=0; 
		for(int i=1; i<=n; ++i)
		{
			int x; cin>>x;
			if(!x) ++cnt0;
			else a.push_back(x);
		}
		while(a.size()>1)
		{
			b.clear(); 
			if(cnt0) b.push_back(a[0]),--cnt0;
			for(int i=1; i<a.size(); ++i)
			{
				int cj=a[i]-a[i-1];
				if(!cj) ++cnt0;
				else b.push_back(cj);
			}
			sort(b.begin(),b.end());
			a=b;
		}
		cout<<(!a.size()?0:a[0])<<'\n';
	}
}