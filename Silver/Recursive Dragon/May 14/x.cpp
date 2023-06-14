#include <bits/stdc++.h>
using namespace std;

int main(){
    int total = 0;
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            for (int k = 0; k < 26; k++){
                for (int a = 0; a < 26; a++){
                    for (int b = 0; b < 26; b++){
                        total++;
                        if (i == 0 && j == 18 && k == 19 && a == 0 && b == 18){
                            cout << floor(float(float(total)/520));
                        }
                    }
                }
            }
        }
    }
}