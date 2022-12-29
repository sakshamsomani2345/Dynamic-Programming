#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m)
{
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (s1[n] == s2[m])
    {
         return 1 + lcs(s1, s2, n - 1, m - 1);
    }
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}
int memo(string s1, string s2, int n, int m, vector<vector<int>> dp)
{
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n] == s2[m])
    {
        dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
        return dp[n][m];
    }
    dp[n][m] = max(memo(s1, s2, n - 1, m, dp), memo(s1, s2, n, m - 1, dp));
    return dp[n][m];
}
int dpe(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return memo(s1, s2, n, m, dp);
}
int tabular(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
            dp[i][0] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
            dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j]==max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << tabular(s1, s2, s1.size(), s2.size() );
}