#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string S;
    fin >> S;
    string censor;
    fin >> censor;
    string constructed;
    for (char i : S){
        constructed.push_back(i);
        if (censor.size() < constructed.size()){
            string end;
            for (int j = constructed.size() - censor.size(); j < constructed.size(); j++){
                end.push_back(constructed[j]);
            }
            if (censor.compare(end) == 0){
                for (int k = 0; k < censor.size(); k++){
                    constructed.pop_back();
                }
            }
        }
    }
    fout << constructed;
}