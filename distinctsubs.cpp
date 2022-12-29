#include <bits/stdc++.h>
using namespace std;
//0-based-indexing
// int dissub(string s1,string s2,int n,int m ){
// if(m<0){
//     return 1;
// }
// if(n<0){
//     return 0;
// }
// if(s1[n]==s2[m]){
//     return dissub(s1,s2,n-1,m-1)+dissub(s1,s2,n-1,m);
// }
//     return dissub(s1,s2,n-1,m);
// }
// 1-based indexing
int dissub(string s1,string s2,int n,int m ){
if(m==0){
    return 1;
}
if(n==0){
    return 0;
}
if(s1[n-1]==s2[m-1]){
    return dissub(s1,s2,n-1,m-1)+dissub(s1,s2,n-1,m);
}
    return dissub(s1,s2,n-1,m);
}
int tabular(string s1,string s2,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int j = 0; j < n+1; j++)
    {
        dp[j][0]=1;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        else{
            dp[i][j]=dp[i-1][j];
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