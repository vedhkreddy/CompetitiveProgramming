#include <iostream>
#include <fstream>
#include <vector>
typedef long long ll;
using namespace std;

void dfs(vector<vector<pair<int,int>>>& graph, vector<int>& visited, int node, int k, int group){
	visited[node] = group;
	for (auto i: graph[node]){
		if (visited[i.first] != -1) continue;
		if (i.second < k) continue;
		dfs(graph, visited, i.first, k, group);
	}
}

bool bisearch(vector<vector<pair<int,int>>>& graph, vector<int>& cows, int k){
	int n = cows.size();
	vector<int> visited(n, -1);
	for (int i = 0; i < n; i++){
		if (visited[i] != -1) continue;
		dfs(graph, visited, i, k, i);
	}
	for (int i = 0; i < n; i++){
		if (visited[cows[i]-1] != visited[i]){
			return false;
		}
	}
	return true;
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
	int n,m;
	fin >> n >> m;
	vector<int> cows(n);
	for (int i = 0; i < n; i++)
		fin >> cows[i];
	vector<vector<pair<int,int>>> graph(n);
	int maxWeight = 0;
	for (int i = 0; i < m; i++){
		int a,b,c;
		fin >> a >> b >> c;
		a--; b--;
		maxWeight = max(maxWeight, c);
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}

	int alreadySorted = 0;
	for (int i = 0; i < n; i++)
		if (cows[i]-1 == i){
			alreadySorted++;
        }
	if (alreadySorted == n){
		fout << -1;
		return 0;
	}
	
	int a = 1, b = maxWeight;
	while ((b-a)>1){
		if (bisearch(graph, cows, (a+b)/2)){
			a += (b-a)/2;
		}else{
			b -= (b-a)/2;
		}
	}
	if (!bisearch(graph, cows, (a+b)/2)) a = b;

	fout << a;

	return 0;
}