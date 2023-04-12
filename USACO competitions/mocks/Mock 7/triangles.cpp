#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
const int MAX_C = 1e4;

struct Fence {
	int x;
	int y;
	long long heightsum;
	long long basesum;
};

Fence fences[MAX_N];
vector<pair<int, int>> xcoords[2 * MAX_C + 1];
vector<pair<int, int>> ycoords[2 * MAX_C + 1];

int main() {
	ifstream cin("triangles.in");
    ofstream cout("triangles.out");

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fences[i].x >> fences[i].y;
		xcoords[fences[i].x + MAX_C].push_back({fences[i].y, i});
		ycoords[fences[i].y + MAX_C].push_back({fences[i].x, i});
	}

	for (int i = 0; i <= 2 * MAX_C; i++) {
		if (xcoords[i].size() > 0) {
			long long curr = 0;
			sort(xcoords[i].begin(), xcoords[i].end());
			for (int j = 1; j < xcoords[i].size(); j++) {
				curr += xcoords[i][j].first - xcoords[	i][0].first;
			}
			fences[xcoords[i][0].second].heightsum = curr;
			for (int j = 1; j < xcoords[i].size(); j++) {
				curr += (2 * j - xcoords[i].size())
						* (xcoords[i][j].first - xcoords[i][j - 1].first);
				fences[xcoords[i][j].second].heightsum = curr;
			}
		}
	}

	for (int i = 0; i <= MAX_C * 2; i++) {
		if (ycoords[i].size() > 0) {
			long long curr = 0;
			sort(ycoords[i].begin(), ycoords[i].end());
			for (int j = 1; j < ycoords[i].size(); j++) {
				curr += ycoords[i][j].first - ycoords[i][0].first;
			}
			fences[ycoords[i][0].second].basesum = curr;
			for (int j = 1; j < ycoords[i].size(); j++) {
				curr += (2 * j - ycoords[i].size())
						* (ycoords[i][j].first - ycoords[i][j - 1].first);
				fences[ycoords[i][j].second].basesum = curr;
			}
		}
	}

	long long total_area = 0;
	for (int i = 0; i < n; i++) {
		total_area += fences[i].heightsum * fences[i].basesum % MOD;
		total_area %= MOD;
	}
	cout << total_area << '\n';
}