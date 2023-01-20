#include <bits/stdc++.h>
using namespace std;
int mincoins(vector<int> x, int index, int target)
{
    // if(target==0){
    //     return 1;
    // }
    if (index == 0)
    {
        // if (target % x[0] == 0)
        // {
        //     return 1;
        // }
    //    else return 0;
    return target%x[0]==0;
    }
    int notpick = mincoins(x, index - 1, target);
    int pick = 0;
    if (x[index] <= target)
    {
        pick =mincoins(x, index, target - x[index]);
    }
    return pick+notpick;
}
int dp(vector<int> x, int target)
{
    vector<vector<int>> dp(x.size(), vector<int>(target + 1,0));
    for (int i = 0; i < target + 1; i++)
    {
        if(i%x[0]== 0)
        {
            dp[0][i] = 1;
        }else{
            dp[0][i]=0;
        }
    }
    for (int i = 1; i < x.size(); i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (x[i] <= j)
            {
                pick = dp[i][j - x[i]];
            }
            dp[i][j] = pick+notpick;
        }
    }
    return dp[x.size()-1][target];
}
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int target;
    cin >> target;
    cout << dp(x,target);
}