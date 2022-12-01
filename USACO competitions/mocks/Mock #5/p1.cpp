#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream cin("moobuzz.in");
    ofstream cout("moobuzz.out");
	int n;
	cin >> n;
	vector<int> v{14, 1, 2, 4, 7, 8, 11, 13};

	int ans = 0;
	ans = (n - 1) / 8;
	ans *= 15;
	ans += v[n % 8];

	cout << ans << endl;
}
