#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                            
																																																																																														
using namespace std;
 
int n;
int a[1000001];
 
int used[1000001];
 
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j < i; j++){
    		used[a[i] + a[j]] ++;
    		mx = max(mx, used[a[i] + a[j]]);
    	}
    }
    cout << mx;
}