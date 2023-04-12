#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        vector<vector<int>> factorizations;
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++){
            int a; cin >> a; v.push_back(a);
        }
        for (int i = 0; i < n; i++){
            factorizations.push_back(factor(v[i]));
        }
        vector<int> factors;
        for (int i = 0; i < n; i++){
            sort(factorizations[i].begin(), factorizations[i].end());
        }
        for (vector<int> i : factorizations){
            for (int j = 0; j < size(i); j++){
                if (j == 0){
                    factors.push_back(i[j]);
                }
                else if (i[j-1] != i[j]){
                    factors.push_back(i[j]);
                }
                else{
                    continue;
                }
            }
        }
        sort(factors.begin(), factors.end());
        set<int> s(factors.begin(), factors.end());
        if (size(s) < size(factors)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}