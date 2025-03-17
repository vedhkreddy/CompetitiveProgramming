/*
Observations: we can compress paths in order to make lives easier + use distinguishability 
continually deleting edges is the key
1) construct graph
2) mark endpoints (leaves)
3) for each leave, compress as much as possible

create a compress function 

compress recursive function
    simple dfs
    if compress[child] = true, then set compress[parent] = true if the child is the only child
        make it a pair to keep track of the last leaf that will get compressed up
    case 2: more than one child but one child specifically is set to be true in the compression
        we need to delete the 

instead: compression function up from the leaf

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> toleaf[1000005];
vector<int> awayfromleaf[1000005];



int depths[1000005];
bool compressed[1000005];
int curpos[1000005];
bool visited[1000005];

//initialize depths

void finddepths(int x){
    visited[x] = true;
    for (int i = 0; i < toleaf[x].size(); i++){
        if (!visited[toleaf[x][i]]){
            depths[toleaf[x][i]] = depths[x] + 1;
            finddepths(toleaf[x][i]);
        }
    }
}

void compress(int x, int child, int compsvalue){

    if (compsvalue == -1){
        //base case intitila leaf case
        compressed[x] = true;
        compress(awayfromleaf[x][0], x, x);
    }
    else if (x == 0 && toleaf[x].size() == 1 && compressed[child] == true){
        if (toleaf[0].size() != 1) return;
        compressed[0] = true;
        depths[compsvalue] = depths[0];
    }
    //compress up from the leaf
    else if (toleaf[x].size() == 1 && compressed[child] == true){
        compressed[x] = true;
        depths[compsvalue] = depths[x];
        //we actually have to do the compression/switch around now
        awayfromleaf[compsvalue] = {awayfromleaf[x][0]};
        awayfromleaf[x].clear();
        //update the curposses in order to pop and swap and delete
        int index = curpos[x];
        toleaf[awayfromleaf[x][0]][index] = toleaf[awayfromleaf[x][0]].back();
        toleaf[awayfromleaf[x][0]].pop_back();
        toleaf[awayfromleaf[x][0]].push_back(compsvalue);
        curpos[compsvalue] = toleaf[awayfromleaf[x][0]].size() - 1;
        //go up!
        compress(awayfromleaf[x][0], x, compsvalue);
    }

    else{
        //no compression, just return
        return;
    }
}

int main(){
    //ifstream cin("b.in");
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        awayfromleaf[i].push_back(a);
        toleaf[a].push_back(i);
        curpos[i] = toleaf[a].size() - 1;
    }
    finddepths(0);
    int amt = 0;
    for (int i = 1; i <= n; i++){
        if (toleaf[i].size() == 0){
            compress(i, -1, -1);
            amt++;
        }
    }
    for (int i = 0; i < amt; i++){
        int a; cin >> a;
        cout << depths[a] << endl;
        int x = awayfromleaf[a][0];
        awayfromleaf[a].clear();
        //swap and pop using curpos, update both graphs
        int index = curpos[a];
        toleaf[x][index] = toleaf[x].back();
        toleaf[x].pop_back();
        //x is the one that we need to check if the child can be compressed
        if (toleaf[x].size() == 1 && compressed[toleaf[x][0]] == true){
            compress(toleaf[x][0], -1, -1);
        }
    }
}