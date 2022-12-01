#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 20000;

long long a[MAXN], b[MAXN];
long long in[MAXN];
long long out[MAXN];
long long ans[MAXN];

int main(){

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		int x, y;
		cin >> x >> y;
		++ a[x];
		++ b[y];
	}
	
	for(int i = 0; i <= m; ++ i)
		for(int j = 0; j <= m; ++ j)
			in[i + j] += a[i] * a[j], out[i + j] += b[i] * b[j];
		
	
	long long count = 0;
	for(int i = 0; i <= 2 * m; ++ i){
		count += in[i];
		ans[i] = count;
		count -= out[i];
	}
	
	for(int i = 0; i <= 2 * m; ++ i) cout << ans[i] << endl;
	return 0;
}