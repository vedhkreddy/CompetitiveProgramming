#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
multiset<int>s;
const int N=200090;
int a[N];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n+2;i++)a[i]=0;
        for(int i=0;i<n;i++){
            int x;cin>>x;a[x]++;
        }
        ll re=0;
        cout<<a[0]<<" ";
        for(int j=0;j<a[0];j++)s.insert(0);
        for(int i=1;i<=n;i++){
            if(s.size()==0){
                for(int j=i;j<=n;j++)cout<<-1<<" ";break;
            }
            auto x=s.upper_bound(i);x--;
            int z=*x;
            re+=i-1-z;
            s.erase(x);ll w=a[i]+re;
            cout<<w<<" ";
            for(int j=0;j<a[i];j++)s.insert(i);
        }
        cout<<endl;
        s.clear();
    }
}