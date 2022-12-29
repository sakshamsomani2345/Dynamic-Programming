#include <bits/stdc++.h>
using namespace std;
// int lcs(string s1, string s2, int n, int m)
// {
//     if (n < 0 || m < 0)
//     {
//         return 0;
//     }
//     int x = INT_MIN;
//     if (s1[n] == s2[m])
//     {
//          x=1 + lcs(s1, s2, n - 1, m - 1);
//     }
//     return max(max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1)),x);
// }
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
    int maxi=0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi=max(maxi,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return maxi;
}
int main()
{
    string s1;
    cin >> s1;
    cout << tabular(s1, s2, s1.size()-1, s2.size()-1 );
}