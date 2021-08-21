#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=785
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int N;
    fin >> N;
    int cows[N];
    for(int i = 0; i < N; i++){
        int a;  
        fin >> a;
        cows[i] = a;
    }
    int bessieheight = 0;
    int bessieposition = 0;
    for(int i = 0; i < N; i++){
        if (i == 0){
            if (cows[i + 1] < cows[i]){
                bessieposition = i;
                bessieheight = cows[i];
            }
        }
        else if(i == N-1){
            if (cows[N - 2] > cows[N - 1]){
                bessieposition = i;
                bessieheight = cows[i];
            }
        }
        else if(((cows[i - 1] > cows[i] && cows[i + 1] > cows[i] && cows[i-1] <= cows[i+1]) || (cows[i - 1] < cows[i] && cows[i + 1] < cows[i] && cows[i-1] <= cows[i+1])) && bessieheight == 0){
            bessieposition = i;
            bessieheight = cows[i];
            break;
        }
    }
    int counter = 0;
    bool left = false;
    bool right = false;
    if (bessieposition == N-1){
        left = true;
    }
    else if(bessieposition == 0){
        right = true;
    }
    else if(cows[bessieposition-1] > bessieheight){
        left = true;
    }
    else{
        right = true;
    }
    int index = bessieposition;
    int last = 1000001;
    while (true){
        if (left == true){
            if (index == 0){
                break ;
            }
            else if (cows[index - 1] <= bessieheight){
                break ;
            }
            else if (last != cows[index - 1]){
                counter++;
                index--;
                last = cows[index];
            }
            else{
                index--;
            }
        }
        else{
            if (index == 0){
                break ;
            }
            else if (cows[index + 1] >= bessieheight){
                break ;
            }
            else if (last != cows[index + 1]){
                counter++;
                index++;
                last = cows[index];
            }
            else{
                index++;
            }
        }
    }
    fout << counter;
}