#include <bits/stdc++.h>
using namespace std;
int frogjump(vector<int> x, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int energyone = frogjump(x, n - 1) + abs(x[n] - x[n - 1]);
    int energytwo = INT_MAX;
    if (n > 1)
    {
        energytwo = frogjump(x, n - 2) + abs(x[n] - x[n - 2]);
    }
    return min(energyone, energytwo);
}
int memo(vector<int> dp, int n, vector<int> x)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int energyone = memo(dp, n - 1, x) + abs(x[n] - x[n - 1]);
    int energytwo = INT_MAX;
    if (n > 1)
    {
        energytwo = memo(dp, n - 2, x) + abs(x[n] - x[n - 2]);
    }
    return dp[n] = min(energyone, energytwo);
}
// sc=>o(n)
// tc=>o(n)+o(n)
int dp(vector<int> x, int n)
{
    vector<int> array(n + 1, -1);
    return memo(array, n, x);
}
int tabulation(int n, vector<int> x)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int y = dp[i - 1] + abs(x[i] - x[i - 1]);
        int z=INT_MAX;
        if (i > 1)
        {
            z = dp[i - 2] + abs(x[i] - x[i - 2]);
        }
        dp[i]=min(y,z);
    }
    return dp[n];
}
// sc=>o(n)
// tc=>o(n)
int optimised(int n, vector<int> x)
{
   int prev=0;
   int prev2=0;
    for (int i = 1; i <= n; i++)
    {
        int y = prev + abs(x[i] - x[i - 1]);
        int z=INT_MAX;
        if (i > 1)
        {
            z = prev2 + abs(x[i] - x[i - 2]);
        }
        int curr=min(y,z);
        prev2=prev;
        prev=curr;

    }
    return prev;
}
// sc=>o(n)
// tc=>o(1)
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x[i] = a;
    }
    cout << optimised(n - 1, x);
}