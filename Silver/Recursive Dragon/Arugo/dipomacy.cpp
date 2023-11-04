#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define fast 
 
 

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        int n, m;cin>>n>>m;
        vector<int>a[m+1];
        vector<pair<int, int>>vv;
        int ans[m+1]={0};
        for(int i=0;i<m;i++){
            int x;cin>>x;
            
            for(int j=0;j<x;j++){
                int tt;cin>>tt;
                a[i+1].push_back(tt);
            }
            vv.push_back({x, i+1});
        }
        
        sort(vv.begin(), vv.end());
        map<int, int>mm;
        for(int i=0;i<vv.size();i++){
            
            for(int j=0;j<a[vv[i].second].size();j++){
                if(mm[a[vv[i].second][j]]<(m+1)/2){
                    ans[vv[i].second]=a[vv[i].second][j];
                    mm[a[vv[i].second][j]]++;
                    break;
                }
            }
        }
        int flag=1;
        for(int i=1;i<=m;i++)if(ans[i]==0){
            flag=0;
            break;
        }
        if(flag==0)cout<<"NO";
        else{ cout<<"YES"<<endl;
            for(int i=1;i<=m;i++)cout<<ans[i]<<" ";}
        cout<<endl;
    }
    
