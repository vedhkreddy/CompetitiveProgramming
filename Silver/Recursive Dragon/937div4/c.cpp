#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int hour = stoi(s.substr(0,2));
        int minute = stoi(s.substr(3,2));
        string period = "";
        if (hour > 12){
            hour -= 12;
            period = "PM";
        }
        else if (hour == 12){
            period = "PM";
        }
        else{
            period = "AM";
        }
        if (hour == 0){
            hour = 12;
        }
        string x = to_string(hour);
        string y = to_string(minute);
        if (x.size() == 1) x = "0" + x;
        if (y.size() == 1) y = "0" + y;
        cout << x << ":" << y << " " << period << endl;
    }
}