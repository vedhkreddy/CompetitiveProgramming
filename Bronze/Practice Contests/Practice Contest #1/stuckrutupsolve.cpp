#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include "../../../../DebuggingStuff/prettyprint.hpp"
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1060
    int N;
    cin >> N;
    class Cow {
        public:
            char dir;
            int x;
            int y;
            bool stopped;
            int count;
            int id;
            Cow(char dir, int x, int y, bool stopped, int count, int id){
                (*this).dir = dir;
                (*this).x = x;
                (*this).y = y;
                (*this).stopped = stopped;
                (*this).count = count;
                (*this).id = id;
            }
    };
    vector<Cow> allcows;
    for(int i = 0; i < N; i++){
        char a;
        int b;
        int c;
        cin >> a >> b >> c;
        Cow cow(a, b, c, false, 0, i); 
        allcows.push_back(cow);
    }
    while (true){
        int length = allcows.size();
        double count = 1e10;
        vector<int> idstopped;
        double cur = 1e10;
        int idcow = -1;
        for(int i = 0; i < length - 1; i++){
            for(int j = i+1; j < length; j++){
                cur = 1e10;
                if (allcows[i].dir != allcows[j].dir){
                    if (allcows[i].dir == 'N'){
                        /*
                        n means the north cow has already gone through the intersection, 
                            meaning the east cow is the one that will get stopped
                        e means the same thing except for e
                        nc stands for north closer and so it means that the north cow is 
                            closer to the intersection point than the east cow
                        ec means the same thing except for e
                        */
                        bool n = allcows[j].x < allcows[i].x 
                                    && allcows[i].y >= allcows[j].y 
                                    && allcows[i].y - allcows[i].count <= allcows[j].y 
                                    && allcows[j].stopped == 0;
                        bool e = allcows[j].x >= allcows[i].x 
                                    && allcows[i].y < allcows[j].y 
                                    && allcows[j].x - allcows[j].count <= allcows[i].x 
                                    && allcows[i].stopped == 0;
                        bool nc = false; bool ec = false;
                        if (allcows[i].stopped == 0 && allcows[j].stopped == 0){
                            nc = allcows[j].x < allcows[i].x 
                                    && allcows[i].y < allcows[j].y 
                                    && allcows[i].x - allcows[j].x > allcows[j].y - allcows[i].y;
                            ec = allcows[j].x < allcows[i].x 
                                    && allcows[i].y < allcows[j].y 
                                    && allcows[i].x - allcows[j].x < allcows[j].y - allcows[i].y;
                        }
                        if (n == true || nc == true){
                            cur = allcows[i].x - allcows[j].x;
                            idcow = allcows[j].id;
                        }
                        else if (e == true || ec == true){
                            cur = allcows[j].y - allcows[i].y;
                            idcow = allcows[i].id;
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
                        bool n = allcows[i].x < allcows[j].x 
                                    && allcows[j].y >= allcows[i].y 
                                    && allcows[j].y - allcows[j].count <= allcows[i].y 
                                    && allcows[i].stopped == 0;
                        bool e = allcows[i].x >= allcows[j].x 
                                    && allcows[j].y < allcows[i].y 
                                    && allcows[i].x - allcows[i].count <= allcows[j].x 
                                    && allcows[j].stopped == 0;
                        bool nc = false; bool ec = false;
                        if (allcows[i].stopped == 0 && allcows[j].stopped == 0){
                            nc = allcows[i].x < allcows[j].x 
                                    && allcows[j].y < allcows[i].y 
                                    && allcows[j].x - allcows[i].x > allcows[i].y - allcows[j].y;
                            ec = allcows[i].x < allcows[j].x    
                                    && allcows[j].y < allcows[i].y 
                                    && allcows[j].x - allcows[i].x < allcows[i].y - allcows[j].y;
                        }
                        if (n == true || nc == true){
                            cur = allcows[j].x - allcows[i].x;
                            idcow = allcows[i].id;
                        }
                        else if (e  == true || ec == true){
                            cur = allcows[i].y - allcows[j].y;
                            idcow = allcows[j].id;
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
                else if (allcows[i].dir == 'E' && allcows[i].y == allcows[j].y){
                    if (allcows[i].x < allcows[j].x){
                        cur = allcows[j].x - allcows[i].x;
                        idcow = allcows[i].id;
                    }
                    else{
                        cur = allcows[i].x - allcows[j].x;
                        idcow = allcows[j].id;
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
                else if (allcows[i].dir == 'N' && allcows[i].x == allcows[j].x){
                    if (allcows[i].y < allcows[j].y){
                        cur = allcows[j].y - allcows[i].y;
                        idcow = allcows[i].id;
                    }
                    else{
                        cur = allcows[i].y - allcows[j].y;
                        idcow = allcows[j].id;
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
        if (idstopped.size() == 0){
            for (Cow c : allcows){
                if (c.stopped == 1){
                        cout << c.count + 1 << endl;
                    }
                else{
                        cout << "Infinity" << endl;
                    }
            }
            return 0;
        }        
        for(Cow v : allcows){
            for(int i : idstopped){
                if (v.id == i){
                    allcows[v.id].count += count - 1;
                    allcows[v.id].stopped = 1;
                    v.stopped = true;
                    if (v.dir == 'E'){
                        allcows[v.id].x += count - 1;
                    }
                    else{
                        allcows[v.id].y += count - 1;
                    }
                }
            }
            if (v.stopped != true){
                allcows[v.id].count += count;
                if (v.dir == 'E'){
                    allcows[v.id].x += count;
                }
                else{
                    allcows[v.id].y += count;
                }
            }
        }
        bool allstopped = true;
        for (Cow v : allcows){
            if (v.stopped == false){
                allstopped = false;
                break;
            }
        }
        if (allstopped == true){
            for(Cow v : allcows){
                cout << v.count + 1 << endl;
            }
            return 0;
        }
    }
}