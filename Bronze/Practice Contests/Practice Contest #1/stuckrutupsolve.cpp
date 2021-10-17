#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include "../../../../DebuggingStuff/prettyprint.hpp"
using namespace std;

int main(){
    ifstream fin("stuckrutupsolve.in");
    int N;
    cin >> N;
    // stores: [Direction, x coordinate, y coordinate, stopped (0 no, 1 yes), squarecount, id]
    vector<vector<int>> allcows;
    for(int i = 0; i < N; i++){
        char a;
        int b;
        int c;
        cin >> a >> b >> c;
        allcows.push_back({a, b, c, 0, 0, i});
    }
    //cout << allcows << endl;
    //cout << allcows << endl;
    while (true){
        int length = allcows.size();
        double count = 1e10;
        vector<int> idstopped;
        double cur = 1e10;
        int idcow = -1;
        for(int i = 0; i < length - 1; i++){
            for(int j = i+1; j < length; j++){
                cur = 1e10;
                if (allcows[i][0] != allcows[j][0]){
                    if (allcows[i][0] == 'N'){
                        bool n = allcows[j][1] < allcows[i][1] && allcows[i][2] >= allcows[j][2] && allcows[i][2] - allcows[i][4] <= allcows[j][2] && allcows[j][3] == 0;
                        bool e = allcows[j][1] >= allcows[i][1] && allcows[i][2] < allcows[j][2] && allcows[j][1] - allcows[j][4] <= allcows[i][1] && allcows[i][3] == 0;
                        bool nc = false; bool ec = false;
                        if (allcows[i][3] == 0 && allcows[j][3] == 0){
                            nc = allcows[j][1] < allcows[i][1] && allcows[i][2] < allcows[j][2] && allcows[i][1] - allcows[j][1] > allcows[j][2] - allcows[i][2];
                            ec = allcows[j][1] < allcows[i][1] && allcows[i][2] < allcows[j][2] && allcows[i][1] - allcows[j][1] < allcows[j][2] - allcows[i][2];
                        }
                        if (n == true || nc == true){
                            cur = allcows[i][1] - allcows[j][1];
                            idcow = allcows[j][5];
                        }
                        else if (e == true || ec == true){
                            cur = allcows[j][2] - allcows[i][2];
                            idcow = allcows[i][5];
                        }
                        if (cur < count){
                            count = cur;
                            idstopped.clear();
                            idstopped.push_back(idcow);
                        }
                        else if (cur == count && cur != 1e10){
                            idstopped.push_back(idcow);
                        }
                    }
                    else{
                        //n means the north cow has already gone through the intersection, meaning the east cow is the one that will get stopped
                        //e means the same thing except for e
                        //nc stands for north closer and so it means that the north cow is closer to the intersection point than the east cow
                        //ec means the same thing except for e
                        bool n = allcows[i][1] < allcows[j][1] && allcows[j][2] >= allcows[i][2] && allcows[j][2] - allcows[j][4] <= allcows[i][2] && allcows[i][3] == 0;
                        bool e = allcows[i][1] >= allcows[j][1] && allcows[j][2] < allcows[i][2] && allcows[i][1] - allcows[i][4] <= allcows[j][1] && allcows[j][3] == 0;
                        bool nc = false; bool ec = false;
                        if (allcows[i][3] == 0 && allcows[j][3] == 0){
                            nc = allcows[i][1] < allcows[j][1] && allcows[j][2] < allcows[i][2] && allcows[j][1] - allcows[i][1] > allcows[i][2] - allcows[j][2];
                            ec = allcows[i][1] < allcows[j][1] && allcows[j][2] < allcows[i][2] && allcows[j][1] - allcows[i][1] < allcows[i][2] - allcows[j][2];
                        }
                        if (n == true || nc == true){
                            cur = allcows[j][1] - allcows[i][1];
                            idcow = allcows[i][5];
                        }
                        else if (e  == true || ec == true){
                            cur = allcows[i][2] - allcows[j][2];
                            idcow = allcows[j][5];
                        }
                        if (cur < count){
                            count = cur;
                            idstopped.clear();
                            idstopped.push_back(idcow);
                        }
                        else if (cur == count && cur != 1e10){
                            idstopped.push_back(idcow);
                        }
                    }
                }
                else if (allcows[i][0] == 'E' && allcows[i][2] == allcows[j][2]){
                    if (allcows[i][1] < allcows[j][1]){
                        cur = allcows[j][1] - allcows[i][1];
                        idcow = allcows[i][5];
                    }
                    else{
                        cur = allcows[i][1] - allcows[j][1];
                        idcow = allcows[j][5];
                    }
                    if (cur < count){
                        count = cur;
                        idstopped.clear();
                        idstopped.push_back(idcow);
                    }
                    else if (cur == count && cur != 1e10){
                        idstopped.push_back(idcow);
                    }
                }
                else if (allcows[i][0] == 'N' && allcows[i][1] == allcows[j][1]){
                    if (allcows[i][2] < allcows[j][2]){
                        cur = allcows[j][2] - allcows[i][2];
                        idcow = allcows[i][5];
                    }
                    else{
                        cur = allcows[i][2] - allcows[j][2];
                        idcow = allcows[j][5];
                    }
                    if (cur < count){
                        count = cur;
                        idstopped.clear();
                        idstopped.push_back(idcow);
                    }
                    else if (cur == count && cur != 1e10){
                        idstopped.push_back(idcow);
                    }
                }
            }
        }
        for (int i : idstopped){
            //cout << i << endl;
        }
        if (idstopped.size() == 0){
            //cout << allcows;
            for (vector<int> v : allcows){
                if (v[3] == 1){
                        cout << v[4] + 1 << endl;
                    }
                else{
                        cout << "Infinity" << endl;
                    }
            }
            return 0;
        }        
        for(vector<int> v : allcows){
            for(int i : idstopped){
                if (v[5] == i){
                    allcows[v[5]][4] += count - 1;
                    allcows[v[5]][3] = 1;
                    v[3] = 1;
                    if (v[0] == 'E'){
                        allcows[v[5]][1] += count - 1;
                    }
                    else{
                        allcows[v[5]][2] += count - 1;
                    }
                }
            }
            if (v[3] != 1){
                allcows[v[5]][4] += count;
                if (v[0] == 'E'){
                    allcows[v[5]][1] += count;
                }
                else{
                    allcows[v[5]][2] += count;
                }
            }
        }
        bool allstopped = true;
        for (vector<int> v : allcows){
            if (v[3] == 0){
                allstopped = false;
                break;
            }
        }
        if (allstopped == true){
            for(vector<int> v : allcows){
                cout << v[4] + 1 << endl;
            }
            return 0;
        }
    }
}