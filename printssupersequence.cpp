#include <bits/stdc++.h>
using namespace std;
string tabular(string s1, string s2, int n, int m)
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
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=n;
    int j=m;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }else{
            ans+=s2[j-1];
            j--;}
    }
    while (j>0)
    {
        ans+=s2[j-1];
        j--;
    }
     while (i>0)
    {
        ans+=s1[i-1];
        i--;
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
// tc=>o(n+m)
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << lcs(s1, s2, s1.size() - 1, s2.size() - 1);
    cout << tabular(s1, s2, s1.size(), s2.size() );
}