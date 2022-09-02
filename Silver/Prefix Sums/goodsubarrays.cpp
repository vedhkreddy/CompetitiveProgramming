#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++){
        ll sol = 0;
        ll num;
        cin >> num;
        ll list[num];
        for (ll j = 0; j < num; j++){
            char a;
            cin >> a;
            if (j != 0){
                list[j] = list[j-1] + int(a)-48;
                continue;
            }
            list[j] = int(a)-48;
        }
        map<ll, ll> numbers;
        numbers[0] = 1;
        for (ll j = 0; j < num; j++){
            if (numbers.count(list[j] - j - 1)){
                numbers[list[j] - j - 1]++;
                continue;
            }
            numbers[list[j] - j - 1] = 1;
        }
        map<ll, ll>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); it++){
            ll cur = it->second;
            sol += cur * (cur-1) / 2;
        }
        cout << sol << endl;
    }
}