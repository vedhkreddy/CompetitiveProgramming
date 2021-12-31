#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check(long long G, long long H){
    if (G == 1 || H == 1){
        return true;
    }
    return false;
}

int main(){
    //ifstream cin("lonelyphoto.in");
    long long N;
    cin >> N;
    char s[N];
    for (long long i = 0; i < N; i++){  
        cin >> s[i];
    }
    long long count = 0;
    for (long long i = 0; i < N; i++){
        long long G = 0;
        long long H = 0;
        long long indexposition = i;
        while (indexposition != N+1){
            if (G + H > 2 && check(G, H)){
                count++;
            }
            if (s[indexposition] == 'G'){
                G++;            
            }
            else{
                H++;
            }
            indexposition++;
        }
    }
    cout << count;
}