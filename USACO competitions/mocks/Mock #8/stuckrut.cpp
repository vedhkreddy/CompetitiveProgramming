#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
using namespace std;
struct cow {
	int x, y, id;
};
int main()
{
	int n;
	cin >> n;
	vector<cow> cowsN, cowsE;
	for (int i = 1; i <= n; ++i) {
		cow c;
		char dir;
		cin >> dir >> c.x >> c.y;
		c.id = i;
		cin.ignore();
		if (dir == 'N') {
			cowsN.push_back(c);
		}
		else {
			cowsE.push_back(c);
		}
	}
	sort(cowsN.begin(), cowsN.end(), [](const cow &a, const cow &b){
		return a.x == b.x ? a.y > b.y : a.x < b.x;
	});
	sort(cowsE.begin(), cowsE.end(), [](const cow &a, const cow &b){
		return a.y == b.y ? a.x > b.x : a.y < b.y;
	});
	vector<int> cnt(n + 1, 0), stopped(n + 1, 0);
	for (size_t i = 0; i < cowsN.size(); ++i) {
		int curx = cowsN[i].x, cury = cowsN[i].y, Nid = cowsN[i].id;
		for (size_t j = 0; j < cowsE.size() && (stopped[Nid] == 0); ++j) {
			int refx = cowsE[j].x, refy = cowsE[j].y, Eid = cowsE[j].id;
			if (curx < refx || cury > refy || stopped[Eid] != 0) { continue; }
			if (curx - refx < refy - cury) { 
				cnt[Eid] += 1 + cnt[Nid];
				stopped[Nid] = Eid;
			}
			if (curx - refx > refy - cury) { 
				cnt[Nid] += 1 + cnt[Eid];
				stopped[Eid] = Nid;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << cnt[i] << endl;
	}
	return 0;
}
