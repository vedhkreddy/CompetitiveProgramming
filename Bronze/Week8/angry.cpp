#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=592
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N;
    fin >> N;
    int bales[N];
    for(int i = 0; i < N; i++){
        fin >> bales[i];
    }
    sort(bales, bales + N);
    int big = 0;
    int bale;
    for(int i = 0; i < N; i++){
        int counter = 1;
        int indexposition = i+1;
        int radius = 0;
        bool missed = false;
        while (indexposition != N){
            if (bales[indexposition] - bales[indexposition - 1] <= radius){
                indexposition++;
                counter++;
                missed = false;
            }
            else if (missed == false){
                missed = true;
                radius++;
            }
            else{
                break;
            }
        }
        radius = 0;
        indexposition = i - 1;
        missed = false;
        while (indexposition != -1){
            if (bales[indexposition + 1] - bales[indexposition] <= radius){
                indexposition--;
                counter++;
                missed = false;
            }
            else if (missed == false){
                missed = true;
                radius++;
            }
            else{
                break;
            }
        }

        if (counter > big){
            big = counter;
            bale = bales[i];
        }
    }
    for(int i = 0; i < N; i++){
        cout << bales[i] << endl;
    }
    fout << big;
    cout << big << " " << bale << endl;
}