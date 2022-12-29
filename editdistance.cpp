#include <bits/stdc++.h>
using namespace std;
int editdist(string s1, string s2, int n, int m)
{
    if (m < 0)
    {
        return n + 1;
    }
    if (n < 0)
    {
        return m + 1;
    }
    if (s1[n] == s2[m])
    {
        return editdist(s1, s2, n - 1, m - 1);
    }
    int x = 1 + editdist(s1, s2, n, m - 1);
    int y = 1 + editdist(s1, s2, n - 1, m);
    int z = 1 + editdist(s1, s2, n - 1, m - 1);
    return min(x, min(y, z));
}
int tabular(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = i;
    }
      for (int j = 0; j < m + 1; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {

                int x = 1 + dp[i - 1][j - 1];
                int y = 1 + dp[i][j - 1];
                int z = 1 + dp[i - 1][j];
                dp[i][j] = min(x, min(y, z));
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << tabular(s1, s2, s1.size(), s2.size());
}