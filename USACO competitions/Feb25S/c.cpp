/*
becomes a+b, b
or a, a+b
two operations, can choose any
in the end, you can create a system of linear equations to model the problem
a + xb + ya = c
b + xa + yb = d
feels a little complicated

solve for x and y and see if they are integers

4
5 3 5 2
5 3 8 19
5 3 19 8
5 3 5 3

second tc: gets a little bit complicated bc we dont know the order of the operations (order matters in this case)

thing is: we know that we have to end up at 8 and 19
to get 19, we have to add by some amount of 8 because we can't reach 8 by adding 19
if work backwards, we do subtraction to get 19 - 8 = 11
11 8
3 8
3 5
3 operations, checks out

1000000000 1000000000 1000000000 999999999
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ifstream cin ("c.in");
    int t; cin >> t;
    for (int tc = 0; tc < t; tc++){
        //each op counts as one
        //working backwards creates the order insstead of two possible cases
        bool correct = false;
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll res = 0;
        while (c >= a && d >= b){
            if (c == a && d == b){
                cout << res << endl;
                correct = true;
                break;
            }
            bool switched = false;
            if (c > d){
                //decrement until it hits c OR until the things switch
                ll tmp = c;
                c = d;
                d = tmp;
                ll tmp1 = a;
                a = b;
                b = tmp1;
                switched = true;

            }
            ll x = d - c;
            if (x > c){
                if (c == a && d > b){
                    if ((d - b) % c == 0){
                        res += (d - b) / c;
                        cout << res << endl;
                        correct = true;
                        break;
                    }
                }
                //now we know we have to subtract until they switch
                int ops = x / c + 1;
                res += ops;
                d -= c * ops;
            }   
            else{
                d -= c;
                res++;
            }   
            if (switched == true){
                ll tmp = c;
                c = d;
                d = tmp;
                ll tmp1 = a;
                a = b;
                b = tmp1;
            }
        }
        if (correct != true) cout << -1 << endl;
    }
    
}
