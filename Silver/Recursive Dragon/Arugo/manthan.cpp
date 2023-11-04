#include <bits/stdc++.h>
 
using namespace std;

 
const int N =2000;
char a[N];
int b[N];
int n;
 
bool good(int j){
  if (a[j-1]=='=')
    return b[j-1]==b[j];
  if(a[j-1]=='L')
    return b[j-1]>b[j];
  return b[j-1]<b[j];
}
 
 
int main(){
  scanf("%d %s",&n,a);
  
  b[0]=1;
  for(int i=1;i<n;i++){
    if (a[i-1]=='R')
      b[i]=b[i-1]+1;
    else
    if(a[i-1]=='=')
      b[i]=b[i-1];
    else{
      b[i]=1;
      if (b[i-1]==1){
        int j=i;
        while (j>0 && !good(j))b[j-1]++,j--;
      }
    }
  }
 
  for(int i = 0; i < n; i++)
    printf("%d ",b[i]);
  puts("");
  return 0;
}