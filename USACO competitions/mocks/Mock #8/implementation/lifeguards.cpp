#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    ofstream cout("lifeguards.out");
    ifstream cin("lifeguards.in");
	
	int N;
	cin >> N;
	
	vector<pair<int, int>> shifts(N + 1);
	for (int i = 1; i <= N; ++i) {
		int start, end; 
		cin >> start >> end;
		shifts[i] = {start, end};
	}

	sort(shifts.begin() + 1, shifts.end());

	int Time = 0, MaxCurTime = 0, MinLoneTime = 1e9;
	shifts.push_back({shifts[N].second, 0});

	for (int i = 1; i <= N; ++i) {
		int LoneTime = min(shifts[i + 1].first, shifts[i].second) - max(shifts[i].first, MaxCurTime);
		MinLoneTime = max(0, min(MinLoneTime, LoneTime));
		Time += max(0, shifts[i].second - max(MaxCurTime, shifts[i].first));
		MaxCurTime = max(MaxCurTime, shifts[i].second);
	}

	cout << Time - MinLoneTime << '\n';

}   
