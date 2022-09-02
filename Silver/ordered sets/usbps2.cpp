#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct mouse{
    int price;
    int type;
};

bool cmp(mouse a, mouse b){
    return a.price < b.price;
}

int main(){
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<mouse> v;
    for (int i = 0; i < m; i++){
        mouse d;
        cin >> d.price;
        string s;
        cin >> s;
        if (s[0] == 'U'){
            d.type = 0;
        }
        else{d.type = 1;}
        v.push_back(d);
    }
    sort(v.begin(), v.end(), cmp);
    long long cost = 0;
    int computers = 0;
    for (mouse d : v){
        if (d.type == 0){
            if (a > 0){
                a--;
                computers++;
                cost += d.price;
            }
            else if (c > 0){
                c--;
                computers++;
                cost += d.price;
            }
        }
        else{
            if (b > 0){
                b--;
                computers++;
                cost += d.price;
            }
            else if (c > 0){
                c--;
                computers++;
                cost += d.price;
            }
        }
    }
    cout << computers << " " << cost; 
}