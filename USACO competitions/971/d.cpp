#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        vector<pair<long long, long long>> nums;
        map<long long, long long> b;
        set<pair<long long, long long>> check;
        long long ans = 0;
        
        for (long long i = 0; i < n; i++) {
            long long x, y;
            cin >> x >> y;
            nums.push_back({x, y});
            b[x]++;
            check.insert({x, y});
        }
        
        for (auto &entry : b) {
            if (entry.second == 2) {
                ans += n - 2;
            }
        }
        
        for (auto &p : check) {
            if (check.count({p.first - 1, p.second ^ 1}) && check.count({p.first + 1, p.second ^ 1})) {
                ans++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
