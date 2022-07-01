#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;
#define int long long

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int32_t main(){
    auto start = chrono::steady_clock::now();
    ifstream fin("rental.in");
    ofstream fout("rental.out");
    int n, m, r;
    fin >> n >> m >> r;
    int cows[n];
    vector<pair<int, int>> buyprices;
    vector<int> rental1;
    int rental[r];
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        buyprices.push_back(make_pair(a, b));
    }
    for(int i = 0; i < r; i++){
        int a;
        fin >> a;
        rental1.push_back(a);
    }
    sort(cows, cows+n, greater<int>());
    sort(rental1.begin(), rental1.end(), greater<int>());
    sort(buyprices.begin(), buyprices.end(), cmp);
    int prev = 0;
    int cur = 0;
    for (int i : rental1){
        rental[cur] = prev + i;
        prev = rental[cur];
        cur++;
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    int milkprice = 0;
    int max = 0;
    int counter = 0;
    for (int i = 0; i <= n; i++){
        int curprice = 0;
        if (i == 0){
            curprice = rental[r-1];
        }
        else{
            int curmilk = cows[i-1];
            while(buyprices.size() != 0){
                int j = 0;
                int a = buyprices[j].first;
                if (buyprices[j].first >= curmilk){
                    buyprices[j].first -= curmilk;
                    milkprice += (buyprices[j].second * curmilk);
                    break;
                }
                else{
                    milkprice += buyprices[j].first * buyprices[j].second;
                    curmilk -= buyprices[j].first;
                    buyprices.erase(buyprices.begin());
                }
            }
            if (n-i >= r){
                curprice += rental[r-1];
            }   
            else if (n - i - 1 <= 0){
                curprice += rental[0];
            }
            else{
                curprice += rental[n-i-1];
            }
            curprice += milkprice;
        }
        if (curprice > max){
            max = curprice;
        }
    }
    fout << max;
    
}