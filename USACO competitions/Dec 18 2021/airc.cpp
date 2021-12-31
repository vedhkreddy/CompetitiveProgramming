#include <iostream>
#include <fstream>
using namespace std;

bool check(int a[], int b[], int N){
    for (int i = 0; i < N; i++){
        if (a[i] != b[i]){
            return true;
        }
    }
    return false;
}

int main(){
    //ifstream cin("airc.in");
    int N;
    cin >> N;
    int wanted[N];
    int have[N];
    int difference[N];
    int zerolist[N];
    for (int i = 0; i < N; i++){
        cin >> wanted[i];
    }
    for (int i = 0 ; i < N; i++){
        cin >> have[i];
        difference[i] = wanted[i] - have[i];
        zerolist[i] = 0;
    }
    
    int count = 0;
    int startfrom = 0;
    while (check(difference, zerolist, N)){
        bool pos = false;
        int index;
        for (int i = startfrom; i < N; i++){
            if (difference[i] != 0){
                if (difference[i] > 0){
                    pos = true;
                }
                index = i;
                break;
            }
            startfrom = i+1;
        }
        int minmax = difference[index];
        int final1 = index;
        for (int i = index; i < N; i++){
            if (pos == false && difference[i] < 0){
                final1++;
                if (difference[i] > minmax){
                    minmax = difference[i];
                }
            }
            else if (pos == true && difference[i] > 0){
                final1++;
                if (difference[i] < minmax){
                    minmax = difference[i];
                }
            }
            else{
                break;
            }
        }
        for (int i = index; i < final1; i++){
            if (pos == false){
                difference[i] -= minmax;
            }
            if (pos == true){
                difference[i] -= minmax;
            }
        }
        if (minmax < 0){
            minmax *= -1;
        }
        count += minmax;
    }
    cout << count;
}