#include <bits/stdc++.h>
using namespace std;
// int mini(int n,int m,vector<vector<int>>& triangle,int t){
// if(n==t-1){
//     return triangle[t-1][m];
// }
//     int y=triangle[n][m]+mini(n+1,m,triangle,t);

// int x=triangle[n][m]+mini(n+1,m+1,triangle,t);
// return min(x,y);
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	// Write your code here.
//         return mini(0,0,triangle,n);

// }
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n,vector<int>(n));
    for (int j = 0; j < n; j++)
    {
        dp[n-1][j]=triangle[n-1][j];
    }
    for (int i = n-2; i >=0; i--)
    {
       for (int j = i; j >=0; j--)
       {
      int y=triangle[i][j]+dp[i+1][j];
      int x=triangle[i][j]+dp[i+1][j+1];
      dp[i][j]=min(x,y);
       }
       
    }
    return dp[0][0];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
}