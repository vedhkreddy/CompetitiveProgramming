#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool isfine[19][19];
char toint[19] = {'1', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
int count1[19];
int count2[19];
int n, m;
vector<string> queries;
void calculatedifferences(string s, string t){
    for (int i = 0; i < n; i++){
        count1[int(s[i])-96]++;
    }
    for (int i = 0; i < m; i++){
        count2[int(t[i])-96]++;
    }
    for (int i = 0; i < 17; i++){
        for (int j = i + 1; j < 18; j++){
            string s1 = "";
            string t1 = "";
            for (int k = 0; k < n; k++){
                if (s[k] == toint[i+1]){
                    s1 += toint[i];
                }
                if (s[k] == toint[j+1]){
                    s1 += toint[j];
                }
            }
            for (int k = 0; k < m; k++){
                if (t[k] == toint[i+1]){
                    t1 += toint[i];
                }
                if (t[k] == toint[j+1]){
                    t1 += toint[j];
                }
            }
            if (s1.compare(t1) == 0 && s.size() != 0){
                isfine[i+1][j+1] = true;
                isfine[j+1][i+1] = true;
            }
        }
    }
}

bool checkquery(string query){
    int qs = query.size();
    if (qs == 1){
        if (count1[int(query[0])-96] == count2[int(query[0])-96]){
            return true;
        }
        else{
            return false;
        }
    }
    for (int i = 0; i < qs - 1; i++){
        for (int j = i+1; j < qs; j++){
            if (isfine[int(query[i])-96][int(query[j])-96] == false){
                return false;
            }
        }
    }
    return true;
}

void printarray(){
    cout << "{" << endl;
    for (int i = 1; i < 5; i++){
        for (int j = 1; j < 5; j++){
            cout << isfine[i][j];
        }
        cout << endl;
    }
    cout << "}" << endl;
}


int main(){
    //ifstream cin("subset.in");
    //ofstream cout("subset.out");
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        string a;
        cin >> a;
        queries.push_back(a);
    }
    calculatedifferences(s, t);
    for (string query : queries){
        if (checkquery(query)){
            cout << "Y";
        }
        else{
            cout << "N";
        }
    }
    cout << endl;
    //printarray();
}