#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=855
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int a, b, c, d, e, f;
    fin >> a >> b >> c >> d >> e >> f;
    pair<int, int> first = make_pair(a, b);
    pair<int, int> second = make_pair(c, d);
    pair<int, int> third = make_pair(e, f);
    pair<int, int> pour = make_pair(1, 2);
    for(int i = 0; i < 100; i++){
        if(pour.first == 1){
            if (first.second + second.second <= second.first){
                second.second += first.second;
                first.second = 0;
            }
            else{
                first.second -= (second.first - second.second);
                second.second = second.first;
            }
        }
        else if(pour.first  == 2){
            if (second.second + third.second <= third.first){
                third.second += second.second;
                second.second = 0;               
            }
            else{
                second.second -= (third.first - third.second);
                third.second = third.first;
            }            
        }
        else{
            if (third.second + first.second <= first.first){
                first.second += third.second;
                third.second = 0;
            }
            else{
                third.second -= (first.first - first.second);
                first.second = first.first;
            }            
        }
        if (pour.first == 2){
            pour.first = 3;
            pour.second = 1;
        }
        else if(pour.first == 3){
            pour.first = 1;
            pour.second += 1;
        }
        else{
            pour.first++;
            pour.second++;
        }   
    }
    fout << first.second << endl << second.second << endl << third.second << endl;
}