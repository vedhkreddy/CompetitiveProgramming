#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=832
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    int N, M, K;
    fin >> N >> M >> K;
    bool init = false;
    int hierarchy[M];
    //reading in hierarchy
    //check if cow1 is in the hierarchy
    for(int i = 0; i < M; i++){
        fin >> hierarchy[i];
        if (hierarchy[i] == 1){
            init = true;
        }
    }
    map<int, int> placements;
    //adding -1 (no cow placed) to all cow positions
    int positions[N];
    for(int i = 0; i < N; i++){
        positions[i] = -1;
    }
    //reading in cows that demand to be placed
    //put them in the positions list and also put them in a map
    for(int i = 0; i < K; i++){
        int a, b;
        fin >> a >> b;
        if (a == 1){
            fout << b;
            return 0;
        }
        placements[a] = b;
        positions[b-1] = a;
    }
    //initialize end value variable
    int count = 0;
    /*
    if cow1 is in the hierarchy
    place the hierarchy leftmost because we
    want to optimize for cow1 to be earliest in
    the line
    */
    if (init == true){
        int position = 0;
        for(int i = 0; i < M; i++){
            bool cow_demands_position = false;
            //if cow demands position, move position there 
            //(it is already placed)
            for(auto const &x : placements){
                if (x.first == hierarchy[i]){
                    cow_demands_position = true;
                    position = x.second - 1;
                    break;
                }
            }
            if (cow_demands_position == false){
                //find first empty slot and place it in
                while(positions[position] != -1){
                    position++;
                }
                positions[position] = hierarchy[i];
            }
        }
        //checking where cow1 is placed
        for(int i = 0; i < N; i++){
            if (positions[i] == 1){
                count = i+1;
            }
        }
    }
    else{
        /*
        place the hierarchy rightmost now
        because cow1 isn't in it and we want
        cow1 to be leftmost
        */
        int position = N-1;
        for(int i = M-1; i > -1; i--){
            bool cow_demands_position = false;
            for(auto const &x : placements){
                if (x.first == hierarchy[i]){
                    cow_demands_position = true;
                    position = x.second - 1;
                    continue;
                }
            }
            if (cow_demands_position == false){
                for(int j = position; j > -1; j--){
                    if (positions[j] == -1){
                        position = j;
                        positions[j] = hierarchy[i];
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if (positions[i] == -1){
                count = i + 1;
                break;
            }
        }
    }
    fout << count;
}