#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
//redo distance thing and make it so that the sqrt of 17 is there

vector<ll> adj_list[1001];
bool visited[1001];
ll counter = 0;
vector<ll> possible;
vector<vector<ll>> cows;
ll n;

void dfs(ll node){
	visited[node] = true;
	counter++;
	for (ll node1 : adj_list[node]){
		if (!visited[node1]){
			dfs(node1);
		}
	}
}

void cleargraph(){
    counter = 0;
    for (ll i = 0; i < 1001; i++){
        visited[i] = false;
        adj_list[i].clear();
    }
}

void constructgraph(ll radius){
    cleargraph();
    ll b = cows.size();
    for (ll i = 0; i < b; i++){
        for (ll j = 0; j < b; j++){
            if (pow(cows[i][0] - cows[j][0], 2) +  pow(cows[i][1] - cows[j][1], 2) <= radius && i != j){
				adj_list[i+1].push_back(j+1);
                adj_list[j+1].push_back(i+1);
			}
        }
    }
}

void constructpossible(){  
    ll b = cows.size();
    for (ll i = 0; i < b; i++){
        for (ll j = 0; j < b; j++){
            if (i != j){
				possible.push_back(pow(cows[i][0] - cows[j][0], 2) +  pow(cows[i][1] - cows[j][1], 2));
			}  
        }
    }
}

bool compare(ll i){ 
    constructgraph(i);
    dfs(1);
    ll a = counter;
    if (counter == n){
        return true;
    }
    return false;
}

int search(){
    set<int> s(possible.begin(), possible.end() );
    possible.assign( s.begin(), s.end() );
    int low = 0;
    int high = possible.size()-1;
    while(low != high && low != high-1){
        if (compare(possible[(low+high)/2])){
            high = (low+high)/2;
        }
        else{
            low = (low+high)/2;
        }
    }
    if (compare(possible[low])){
        return low;
    }
    else{
        return low+1;
    }
}

int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    for (ll i = 0; i < n; i++){
        ll a, b;
        fin >> a >> b;
        cows.push_back({a, b});
    }
    constructpossible();
    sort(possible.begin(), possible.end());
    auto pos = search();
    fout << possible[pos];
}



