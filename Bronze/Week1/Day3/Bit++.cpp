#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //https://codeforces.com/problemset/problem/282/A
    int N;
    cin >> N;
    vector<string> v;
    for(int i = 0; i < N; i++){
        string statement;
        cin >> statement;
        v.push_back(statement);
    }
    int count = 0;
    string plus = "++";
    string minus = "--";
    for(string s : v){
        if (s.find(minus) != string::npos){
            count--;
        }
        else{
            count++;
        }
    }
    cout << count << endl;
}