#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> adj_list[201];
bool visited[201];
vector<vector<int>> cows;
int counter = 0;

void clearvisited(){
	counter = 0;
	for (int i = 0; i < 201; i++){
		visited[i] = false;
	}
}

void dfs(int node){
	visited[node] = true;
	counter++;
	for (int node1 : adj_list[node]){
		if (!visited[node1]){
			dfs(node1);
		}
	}
}

void construct_graph(){
	int N = cows.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (hypot(cows[i][0] - cows[j][0], cows[i][1] - cows[j][1]) <= cows[i][2] && i != j){
				adj_list[i+1].push_back(j+1);
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}
}

int main() {
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	int n; fin >> n;
	for (int i = 0; i < n; i++){
		int a,b,c;
		fin >> a >> b >> c;
		cows.push_back({a, b, c});
	}
	construct_graph();
	int max = -1;
	for (int i = 1; i <= n; i++){
		clearvisited();
		dfs(i);
		if (counter > max){
			max = counter;
		}
	}
	fout << max << endl;
}