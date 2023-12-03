
#include <iostream>
 
using namespace std;
 
 
long long dp[60][60][60][60];
int a[60];
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int p;
    cin >> p;
    if (sum <= p)
    {
        cout << n << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int k = 0; k <= n; k++)
            dp[i][0][k][0] = 1;
    for (int i = 1; i <= n; i++) // Exculde this... this will go to end
        for (int x = 1; x <= n; x++)
            for (int k = 1; k <= n; k++)
                for (int num = 1; num <= p; num++)
                    if (k == i)
                        dp[i][x][k][num] = dp[i][x][k - 1][num];
                    else
                    {
                        dp[i][x][k][num] = dp[i][x][k - 1][num];
                        if (num >= a[k])
                            dp[i][x][k][num] += dp[i][x - 1][k - 1][num - a[k]];
                    }
    long double l = 1;
    for (int i = 1; i <= n; i++)
        l /= i;
    long double t = 0;
    /*for (int i = 1; i <= n; i++)
        for (int x = 1; x <= n; x++)
            for (int num = 0; num <= p; num++)
                cout << i << " " << x << " " << num << " " << dp[i][x][n][num] * x << endl;*/
    cout.precision(6);
    for (int i = 1; i <= n; i++)
        for (int x = 1; x <= n; x++)
            for (int num = max(0, p - a[i] + 1); num <= p; num++)
            {
                long double tmp = dp[i][x][n][num] * x * l;
                for (int fct = 1; fct <= max(x, n - x - 1); fct++)
                {
                    if (fct <= n - x - 1)
                        tmp *= fct;
                    if (fct <= x)
                        tmp *= fct;
                }
                t += tmp;
            }
    cout << fixed << t << endl;
}