#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ifstream cin("haybales.in");
    ofstream cout("haybales.out");
	int bale_num;
	int query_num;
	cin >> bale_num >> query_num;
	vector<int> bales(bale_num);
	for (int i = 0; i < bale_num; i++) {
		cin >> bales[i];
	}
	
	sort(begin(bales), end(bales));
	for (int i = 0; i < query_num; i++) {
		int q_start;
		int q_end;
		cin >> q_start >> q_end;
		cout << upper_bound(begin(bales), end(bales), q_end) 
					- lower_bound(begin(bales), end(bales), q_start) << "\n";
	}
}