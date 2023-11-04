#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
 
const int M = 100;
const int N = 1010;
const int K = 5;
int n;
int a[N][K];
int ans[N];
int ansSz;
 
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < K; j++)
			scanf("%d", &a[i][j]);
	if (n > M) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < n; j++)
			for (int h = j + 1; h < n; h++) {
				if (j == i || h == i) continue;
				int val = 0;
				for (int k = 0; k < K; k++)
					val += (a[j][k] - a[i][k]) * (a[h][k] - a[i][k]);
				ok &= val <= 0; 
			}
		if (ok)
			ans[ansSz++] = i + 1;
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");
 
	return 0;
}