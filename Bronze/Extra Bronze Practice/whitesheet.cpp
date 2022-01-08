#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

double intersection(double a, double b, double c, double d, double e, double f, double g, double h){
    if (min(g,c) - max(a, e) < 0 || min(d, h) - max(b, f) < 0){
        return 0;
    }
    return (min(g,c) - max(a, e)) * (min(d, h) - max(b, f));
}

vector<double> returncoords(double a, double b, double c, double d, double e, double f, double g, double h){
    double ab = max(a, e);
    double cd = min(g, c);
    double ef = max(b, f);
    double gh = min(d, h);
    vector<double> returnthingy = {ab, ef, cd, gh};
    return returnthingy;
}


int main(){
    //ifstream cin("this.in");
    double a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    double intersection1 = intersection(a, b, c, d, e, f, g, h);
    vector<double> infirst = returncoords(a, b, c, d, e, f, g, h);
    double intersection2 = intersection(a, b, c, d, i, j, k, l);
    vector<double> insecond = returncoords(a, b, c, d, i, j, k, l);
    double intersection3 = intersection(infirst[0], infirst[1], infirst[2], infirst[3], insecond[0], insecond[1], insecond[2], insecond[3]);
    double width = c - a;
    double height = d - b;
    
    if (intersection1 + intersection2 - intersection3 == width * height){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}