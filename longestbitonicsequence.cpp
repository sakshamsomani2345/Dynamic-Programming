#include <bits/stdc++.h>
using namespace std;
int lbs(int *arr, int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
    }
     vector<int> dp2(n, 1);
    for (int i = n-1; i >=0; i--)
    {
        for (int j = n-1; j > i; j--)
        {
            if (arr[j] < arr[i] && 1 + dp2[j] > dp2[i])
            {
                  dp2[i] = 1 + dp2[j];
            }
        }
    }
    int maxi=0;
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,dp[i]+dp2[i]-1);
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<lbs(arr,n);
}