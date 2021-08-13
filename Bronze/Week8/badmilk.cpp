#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
    int N, M, D, S;
    fin >> N >> M >> D >> S;
    int sickperson[S];
    int sicktime[S];
    int eventmilk[D];
    int eventtime[D];
    int eventperson[D];
    for(int i = 0; i < D; i++){
        int a, b, c;
        fin >> a >> b >> c;
        eventperson[i] = a; 
        eventmilk[i] = b; 
        eventtime[i] = c;
    }
    for(int i = 0; i < S; i++){
        int a, b;
        fin >> a >> b;
        sickperson[i] = a ;
        sicktime[i] = b ;
    }
    int doses_needed = 0;
    for(int i = 1; i <= M; i++){
        bool possiblybad = true;
        for (int j = 1; j <= S; j++){
            int sick_person = sickperson[j - 1];
            int sick_time = sicktime[j - 1];
            bool curmilkbad = false;
            for(int k = 1; k <= D; k++){
                if (sick_person == eventperson[k - 1] && i == eventmilk[k - 1] && eventtime[k - 1] < sick_time){
                    curmilkbad = true;
                }
            }
            if (curmilkbad == false){
                possiblybad = false;
            }
        }
        if (possiblybad == true){
            int counter = 0;
            for (int j = 1; j <= N; j++){
                bool drankmilk = false;
                for (int k = 1; k <= D; k++){
                    if (j == eventperson[k - 1] && i == eventmilk[k - 1]){
                        drankmilk = true;
                    }
                }
                if (drankmilk){
                    counter++;
                }
            }
            doses_needed = max(doses_needed, counter);
        }
    }
    fout << doses_needed;
}