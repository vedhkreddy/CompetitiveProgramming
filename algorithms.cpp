#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int MAXN = 1000;

//dfs commented because of floodfill visited
/*
vector<int> adj_list[MAXN];
bool visited[MAXN];

void dfs(int node)
{
	visited[node] = true;
	for(int u:adj_list[node]){
		if(!visited[u]){
			dfs(u);
        }
    }
}
*/




//floodfill
int grid[MAXN][MAXN];
int row_num = MAXN;
int col_num = MAXN;
bool visited[MAXN][MAXN];
void floodfill(int r, int c, int color){
	if (
		(r < 0 || r >= row_num || c < 0 || c >= col_num) 
		|| grid[r][c] != color 
		|| visited[r][c] 
	) return;

	visited[r][c] = true;
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}





//floyds




//binary search



//2d prefix sums


int main(){
    cout << "algos in code" << endl;
}