#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int> x, int n)
{
    if (n == 0)
    {
        return x[0];
    }
    int pick=INT_MIN;
    if (n > 1)
    {
    pick = x[n] + maxsum(x, n - 2);
    }
    int notpick = maxsum(x, n-1);
    return max(pick, notpick);
}
// T.C=>o(2^n)
int memo(vector<int> dp,int n,vector<int> x ){
    if (n == 0)
    {
        return x[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
     int pick=INT_MIN;
    if (n > 1)
    {
    pick= x[n] + memo(dp, n - 2,x);
    }
    int notpick = memo(dp, n-1,x);
   return dp[n]= max(pick, notpick);
}
int tabulation(vector<int> x,int n){
    int dp[n+1];
    dp[0]=x[0];
    for (int i = 1; i < n+1; i++)
    {
        int pick=x[i];
    if (i> 1)
    {
    pick+=dp[i-2];
    }
    int notpick = dp[i-1];
    dp[i]= max(pick, notpick);
    }
   return dp[n]; 

}
int dp(vector<int> x, int n)
{
    vector<int> array(n + 1, -1);
    return memo(array, n, x);
}
int main()
{
    vector<int> x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    cout << tabulation(x, n - 1);
}