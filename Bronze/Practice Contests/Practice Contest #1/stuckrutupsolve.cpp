#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("stuckrutupsolve.in");
    int N;
    fin >> N;
    // stores: [Direction, x coordinate, y coordinate, stopped (0 no, 1 yes), squarecount, id]
    vector<vector<int>> allcows;
    for(int i = 0; i < N; i++){
        char a;
        int b;
        int c;
        fin >> a >> b >> c;
        allcows.push_back({a, b, c, 0, 1, i});
    }
    vector<vector<int>> curcows;
    vector<int> z;
    z.push_back(1);
    curcows = allcows;
    while (true){
        int length = curcows.size();
        double count = 1e10;
        int idstopped = -1;
        double cur = 1e10;
        int idcow = -1;
        for(int i = 0; i < length - 1; i++){
            for(int j = i+1; j < length; j++){
                cur = 1e10;
                if (curcows[i][0] != curcows[j][0]){
                    if (curcows[i][0] == 'N'){
                        bool n = curcows[j][1] < curcows[i][1] && curcows[i][2] > curcows[j][2] && curcows[i][2] - curcows[i][4] <= curcows[j][2];
                        bool e = curcows[j][1] > curcows[i][1] && curcows[i][2] < curcows[j][2] && curcows[j][1] - curcows[j][4] <= curcows[i][1];
                        bool nc = curcows[j][1] < curcows[i][1] && curcows[i][2] < curcows[j][2] && curcows[i][1] - curcows[j][1] > curcows[j][2] - curcows[i][2];
                        bool ec = curcows[j][1] < curcows[i][1] && curcows[i][2] < curcows[j][2] && curcows[i][1] - curcows[j][1] < curcows[j][2] - curcows[i][2];
                        if (n == true || nc == true){
                            cur = curcows[i][1] - curcows[j][1];
                            idcow = curcows[j][5];
                        }
                        else if (e == true || ec == true){
                            cur = curcows[j][2] - curcows[i][2];
                            idcow = curcows[i][5];
                        }
                        if (cur < count){
                            count = cur;
                            idstopped = idcow;
                        }
                    }
                    else{
                        //n means the north cow has already gone through the intersection, meaning the east cow is the one that will get stopped
                        //e means the same thing except for e
                        //nc stands for north closer and so it means that the north cow is closer to the intersection point than the east cow
                        //ec means the same thing except for e
                        bool n = curcows[i][1] < curcows[j][1] && curcows[j][2] > curcows[i][2] && curcows[j][2] - curcows[j][4] <= curcows[i][2];
                        bool e = curcows[i][1] > curcows[j][1] && curcows[j][2] < curcows[i][2] && curcows[i][1] - curcows[i][4] <= curcows[j][1];
                        bool nc = curcows[i][1] < curcows[j][1] && curcows[j][2] < curcows[i][2] && curcows[j][1] - curcows[i][1] > curcows[i][2] - curcows[j][2];
                        bool ec = curcows[i][1] < curcows[j][1] && curcows[j][2] < curcows[i][2] && curcows[j][1] - curcows[i][1] < curcows[i][2] - curcows[j][2];
                        if (n == true || nc == true){
                            cur = curcows[j][1] - curcows[i][1];
                            idcow = curcows[i][5];
                        }
                        else if (e  == true || ec == true){
                            cur = curcows[i][2] - curcows[j][2];
                            idcow = curcows[j][5];
                        }
                        if (cur < count){
                            count = cur;
                            idstopped = idcow;
                        }  
                    }
                }
            }
        }
        if (idstopped == -1){
            for (vector<int> v : allcows){
                if (v[3] == 1){
                        cout << v[4] << endl;
                    }
                else{
                        cout << "Infinity" << endl;
                    }
            }
            return 0;
        }        
        curcows.clear();
        for(vector<int> v : allcows){
            if (v[5] == idstopped){
                allcows[v[5]][4] += count - 1;
                allcows[v[5]][3] = 1;
                v[4] += count - 1;
                v[3] = 1;
            }
            else if (v[3] != 1){
                allcows[v[5]][4] += count;
                v[4] += count;
                if (v[0] == 'E'){
                    allcows[v[5]][1] += count;
                    v[1] += count;
                }
                else{
                    allcows[v[5]][2] += count;
                    v[2] += count;
                }
                curcows.push_back(v);
            }
        }
        if (curcows.size() == 0){
            for(vector<int> v : allcows){
                cout << v[4] << endl;
            }
            return 0;
        }
    }
}