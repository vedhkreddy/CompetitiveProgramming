#include <iostream>
#include <string>
using namespace std;
#define int long long

int counts[7];
int32_t main() {
    //waiting, b, e, s, s, i, e 
    string s; cin >> s;
    int countover = 0;
    int output = 0;
    for (int i = 0; i < s.size(); i++){
        counts[0]++;
        if (s[i] == 'b'){
            counts[1] += counts[0];
            counts[0] = 0;
        }
        else if(s[i] == 'e'){
            counts[2] += counts[1];
            counts[1] = 0;
            counts[0] += counts[5];
            countover += counts[5];
            counts[1] = 0;
            counts[5] = 0;
        }
        else if(s[i] == 's'){
            counts[4] += counts[3];
            counts[3] = 0;
            counts[3] += counts[2];
            counts[2] = 0;
        }
        else if(s[i] == 'i'){
            counts[5] += counts[4];
            counts[4] = 0;
        }
        output += countover;
    }

    cout << output << endl;

}