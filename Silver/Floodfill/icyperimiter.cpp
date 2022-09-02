#include <iostream>
#include <fstream>
using namespace std;

char grid[1005][1005];
bool visited[1000000];


void floodfill(int a, int b){

}

int main(){
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

}