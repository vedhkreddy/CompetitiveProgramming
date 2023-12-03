#include <bits/stdc++.h>
using namespace std;
 
// const int MOD = 998'244'353;
const int MOD = 1'000'000'007;
const long long INF = 1'000'000'000LL * 2;
 
bool validAnswer(const string &S)
{
    int N = (int)S.size();
    for (int i = 1; i < N; ++i)
    {
        if (abs(S[i] - S[i - 1]) == 1)
        {
            return false;
        }
    }
    return true;
}
 
void solve()
{
    string S;
    cin >> S;
 
    string odd = "";
    string even = "";
    for (const char &C : S)
    {
        if ((C - 'a') % 2 == 0)
        {
            odd += C;
        }
        else
        {
            even += C;
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
 
    if (validAnswer(odd + even))
    {
        cout << odd + even;
    }
    else if (validAnswer(even + odd))
    {
        cout << even + odd;
    }
    else
    {
        cout << "No answer";
    }
    cout << "\n";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve();
    }
    return 0;
}