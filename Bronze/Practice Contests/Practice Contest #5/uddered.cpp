#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string alphabet, word;
    cin >> alphabet >> word;
    int N = word.size();
    int find = 0;
    int count = 0;
    while (find != -1){
        for (char c : alphabet){
            if (c == word[find]){
                if (find != N - 1){
                    find++;
                }
                else{
                    find = -1;
                    break;
                }
            }
        }
        count++;
    }
    cout << count;
}