#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;

        j--;
    }
    return true;
}
int partition(string a, int i, int n)
{
    if (i == n)
    {
        return 0;
    }
    int cost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (ispalindrome(i, j, a))
        {
            int mincost = 1 + partition(a, j + 1, n);
            cost = min(mincost, cost);
        }
    }
    return cost;
}
int memo(string a, int i, int n, vector<int> dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int cost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (ispalindrome(i, j, a))
        {
            int mincost = 1 + memo(a, j + 1, n, dp);
            cost = min(mincost, cost);
        }
    }
    return dp[i] = cost;
}
int dp(string a)
{
    vector<int> dp(a.size(), -1);
    return memo(a, 0, a.size(), dp);
}
int tabular(string a)
{
    vector<int> dp(a.size() + 1, 0);
    dp[a.size()] = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int cost = INT_MAX;

        for (int j = i; j < a.size(); j++)
        {
            if (ispalindrome(i, j, a))
            {
                int mincost = 1 + dp[j + 1];
                cost = min(mincost, cost);
            }
        }
        dp[i] = cost;
    }
    return dp[0]-1;
}
int main()
{
    string a;
    cin >> a;
    cout << dp(a) ;
}