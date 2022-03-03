#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj_list[100001];
pair<int, int> coordinates[100001];
bool visited[100001];
vector<vector<int>> groups;
vector<int> curgroup;

void dfs(int node){
	visited[node] = true;
    curgroup.push_back(node);
	for (int node1 : adj_list[node]){
		if (!visited[node1]){
			dfs(node1);
		}
	}
}

int findarea(int group){
    int maxx = -1; int maxy = -1; int minx = 400000000; int miny = 400000000;
    for (int i : groups[group]){
        if (coordinates[i].first > maxx){
            maxx = coordinates[i].first;
        }
        if (coordinates[i].first < minx){
            minx = coordinates[i].first;
        }
        if (coordinates[i].second > maxy){
            maxy = coordinates[i].second;
        }
        if (coordinates[i].second < miny){
            miny = coordinates[i].second;
        }
    }
    return (2 * (maxx - minx)) + (2 *(maxy - miny));
}

int main(){
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    fin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a, b;
        fin >> a >> b;
        coordinates[i] = make_pair(a, b);
    }
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    } 
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            groups.push_back(curgroup);
            curgroup.clear();
        }
    }
    int leastperimiter = 400000000;
    for (int i = 0; i < groups.size(); i++){
        int perimiter = findarea(i);
        if (perimiter < leastperimiter){
            leastperimiter = perimiter;
        }
    }

    fout << leastperimiter;
}
