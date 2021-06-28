#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //https://codeforces.com/problemset/problem/71/A
    int N;
    cin >> N;
    vector<string> words;
    for(int i = 0; i < N; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }
    for(string s : words){
        if (s.size() <= 10){
            cout << s << endl;
        }
        else{
            cout << s[0] << (s.size() - 2) << s[(s.size() - 1)] << endl;
        }
    }
}