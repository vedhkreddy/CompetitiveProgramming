#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
 
// change ld to db if neccesary
typedef pair<long long,long long> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pld;
 
typedef set<long long> si;
typedef set<ll> sl;
typedef set<ld> sld;
typedef set<str> ss;
typedef set<pi> spi;
typedef set<pl> spl;
typedef set<pld> spld;
 
typedef vector<long long> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<si> vsi;
typedef vector<sl> vsl;
typedef vector<pld> vpld;
 
#define mp make_pair
#define f first
#define s second
#define sz(x) (long long)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
 
#define forr(i,a,b) for (long long i = (long long)(a); i < (long long)(b); i++)
#define ford(i,a,b) for (long long i = (long long)(a)-1; i >= (long long)(b); i--)
#define trav(a,x) for (auto& a: x)
 
/*
sol notes
    we can only use o(n)
    brute force method: calculate the differences between every element, sort the n^2 res
        take the highest unique n
    optimized method: greedy algo
    sort both arrays
    choose highest to lowest, ignore middle elements (less extreme)

    how would we deal with super small numbers vasya has
*/
 
int main(){
    ifstream cin("c.in");
    long long t;cin >> t;
    while(t--){
        long long n, m; cin >> n >> m;
        vi pet; vi vas;
        forr(i, 0, n){
            long long a; cin >> a; pet.pb(a);
        }
        forr(i, 0, m){
            long long b; cin >> b; vas.pb(b);
        }
        sort(all(pet));
        sort(all(vas));
        //greedy solution
        
        long long p1 = 0; long long p2 = n-1;
        long long v1 = 0; long long v2 = m-1;
        long long ans = 0;
        while(p1 <= p2){
            if (p1 == p2){
                if (abs(pet[p1] - vas[v2]) < abs(pet[p2] - vas[v1])){
                    ans += abs(pet[p2] - vas[v1]);
                }
                else{
                    ans += abs(pet[p1] - vas[v2]); 
                }
                //cout << "here" << endl;
            }
            else{
                ans += abs(pet[p1] - vas[v2]); 
                ans += abs(pet[p2] - vas[v1]);
                //cout << ans << endl;
            }
            p1++; v1++; p2--; v2--;
        }
        cout << ans << endl;
    }
}