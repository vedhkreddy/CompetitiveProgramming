#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int fl(int x, int y) {
	if (x >= 0) {
		return x / y;
	} else {
		return - ((-x + ll(y - 1)) / y);
	}
}
 
int main() {
	int x1, y1, x2, y2;
	int a, b;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	int d1a = fl(x1 + y1, (2 * a));
	int d1b = fl(x1 - y1, (2 * b));
	int d2a = fl(x2 + y2, (2 * a));
	int d2b = fl(x2 - y2, (2 * b));
	cout << max(abs(d1a - d2a), abs(d1b - d2b)) << endl;
}