#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 3000000
int n, q;
int g[N];
void modi(int t, int l, int r, int x ,int y){
	g[t]+=y;
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) modi(t<<1, l, mid, x, y);
	else modi((t<<1)+1, mid+1, r, x, y);
}
int get(int t, int l, int r, int x){
	if (l==r) return r;
	int mid=l+r>>1;
	if (g[t<<1]<x) return get((t<<1)+1,mid+1,r,x-g[t<<1]);
	return get(t<<1,l,mid,x);
}
int main(){
	n=read();q=read();
	for (int i=1;i<=n;i++) modi(1,1,n,read(),1);
	for (int i=1;i<=q;i++){
		int k=read();
		if (k>0) modi(1,1,n,k,1);
		else modi(1,1,n,get(1,1,n,-k),-1);
	}
	if (g[1]) printf("%d\n", get(1,1,n,1));
	else puts("0");
	return 0;
}