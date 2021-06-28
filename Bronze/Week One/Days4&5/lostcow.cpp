#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x,y;
    fin >> x >> y;
    int distancet = 1;
    int distance = 0;
    while (1==1){
        if((x + distancet) >= y && x < y){
            distance += distancet - (abs(y-(x + distancet)));
            break;
        }
        else if((x + distancet) <= y && x > y){
            distance += abs(abs(distancet) - (abs(y-(x + distancet))));
            break;
        }
        else{
            distance += abs(distancet * 2);
            distancet *= -2;
        }
    }
    fout << distance;
}
