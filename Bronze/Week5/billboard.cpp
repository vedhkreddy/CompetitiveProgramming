#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;


int solve(int cowfeed[4], int lawnmower[4]){
    int area = (lawnmower[2] - lawnmower[0]) * (lawnmower[3] - lawnmower[1]);
    if ((lawnmower[3] > cowfeed[3] && lawnmower[1] < cowfeed[1]) && (lawnmower[0] > cowfeed[0] && lawnmower[2] < cowfeed[2])){
        return area;
    }
    //wide enough to take away rows
    if (cowfeed[0] <= lawnmower[0] && cowfeed[2] >= lawnmower[2]){
        //is there any overlapping on the y axis
        if(lawnmower[1] < cowfeed[3] || cowfeed[1] < lawnmower[3] ){
            //subtract from area
            area -= (lawnmower[2] - lawnmower[0]) * (min(lawnmower[3], cowfeed[3]) - max(lawnmower[1], cowfeed[1]));
        }

    }
    //tall enough to take away columns
    else if (cowfeed[1] <= lawnmower[1] && cowfeed[3] >= lawnmower[3]){
        //is there any overlapping on the x axis
        if(lawnmower[0] < cowfeed[2] || cowfeed[0] < lawnmower[2]){
            //subtract from area
            area -= abs((lawnmower[3] - lawnmower[1]) * (min(lawnmower[2], cowfeed[2]) - max(lawnmower[0], cowfeed[0])));
        }

    }
    if (area <= 0){
        return 0;
    }
    return area;
}

int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=783
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int cowfeed[4];
    int lawnmower[4];
    for(int i = 0; i < 4; i++){
        int a;
        fin >> a;
        lawnmower[i] = a;
    }
    for(int i = 0; i < 4; i++){
        int a;
        fin >> a;
        cowfeed[i] = a;
    }

    int solution = solve(cowfeed, lawnmower);
    fout << solution;

}