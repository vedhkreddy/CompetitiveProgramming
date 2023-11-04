#include <bits/stdc++.h>
using namespace std;

map<string, int> occurences;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        vector<string> one;
        vector<string> two;
        vector<string> three;
        for(int a = 0; a < n;a++){
            string s; cin >> s; one.push_back(s);
            occurences[s]++;
        }
        for(int a = 0; a < n;a++){
            string s; cin >> s; two.push_back(s);
            occurences[s]++;
        }
        for(int a = 0; a < n;a++){
            string s; cin >> s; three.push_back(s);
            occurences[s]++;
        }
        int a1 = 0; int a2 = 0; int a3 = 0;
        for(string s : one){
            if (occurences[s] == 1) a1+=3;
            if (occurences[s] == 2) a1+=1;
        }
        for(string s : two){
            if (occurences[s] == 1) a2+=3;
            if (occurences[s] == 2) a2+=1;
        }
        for(string s : three){
            if (occurences[s] == 1) a3+=3;
            if (occurences[s] == 2) a3+=1;
        }
        cout << a1 << " " << a2 << " " << a3 << endl;
        for(string s : one){
            occurences[s] = 0;
        }
        for(string s : two){
            occurences[s] = 0;
        }
        for(string s : three){
            occurences[s] = 0;
        }
    }

}