#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;
#define ARR_SIZE_MAX INT_MAX



int main(){
    char pref[ARR_SIZE_MAX];
    std::cout << sizeof(pref) << std::endl;
    for (int i = 0; i < ARR_SIZE_MAX; i++){
        pref[i] = 'a';
    }
}