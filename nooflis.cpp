#include <bits/stdc++.h>
using namespace std;
int noflis(int *arr, int n)
{
    vector<int> dp(n, 1), count(n,1);
    int maxi=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                count[i]=count[j];
            }else if(arr[j]<arr[i] && 1+dp[j]==dp[i]){
                count[i]+=count[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    int nos=0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i]==maxi){
            nos+=count[i];
        }
    }
    return nos;
   
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

    cout<<noflis(arr,n)
;}