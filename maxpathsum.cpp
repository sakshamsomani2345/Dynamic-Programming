#include <bits/stdc++.h>
using namespace std;
int pathsum(vector<vector<int>> x, int i, int j)
{
    if (j < 0 || j >= x[0].size())
    {
        return -1e9;
    }
    if (i == 0)
    {
        return x[0][j];
    }
    int s = x[i][j] + pathsum(x, i - 1, j);
    int l = x[i][j] + pathsum(x, i - 1, j - 1);
    int r = x[i][j] + pathsum(x, i - 1, j + 1);
    return max(s, max(l, r));
}
// tc=>3^n
int tabulation(vector<vector<int>> x, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = x[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int s = x[i][j] + dp[i - 1][j];
            int l = x[i][j];
            if (j - 1 >= 0)
            {
                l += dp[i - 1][j - 1];
            }
            else
            {
                l += -1e8;
            }
            int r = x[i][j];
            if (j + 1 < m)
            {
                r+=dp[i-1][j+1];
            }else
            {
                r += -1e8;
            }
            dp[i][j]=max(s,max(l,r));
        }
    }
   int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dp[i][j];
        }
    }
    int maxi = -1e8;
    // for (int j = 0; j < m; j++)
    // {
    //     maxi = max(maxi, pathsum(dp, n - 1, j));
    // }

    cout << tabulation(dp,n,m);


}