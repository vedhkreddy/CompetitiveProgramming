#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    //  
    ifstream cin("teleport.in");
    ofstream cout("teleport.out");
    int a, b, x, y;
    bool teleport = false;
    cin >> a >> b >> x >> y;
    int closest, notclosest;

    if(abs(x - a) <= abs(y-a)){
        closest = x;
        notclosest = y;
    }
    else{
        closest = y;
        notclosest = x;
    }

    if (abs(notclosest - b) < abs(a-b) && abs(closest - a) < abs(notclosest - a)){
        teleport = true;
    }
    
    if (teleport == true){
        cout << abs(closest - a) + abs(notclosest - b) << endl;
    }
    else{
        cout << abs(a-b);
    }
    
}

