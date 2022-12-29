#include <bits/stdc++.h>
using namespace std;
vector<int> printlcs(int *arr, int n)
{
vector<int> dp(n, 1), hash(n);
int maxi = 1;
int last = 0;
sort(arr,arr+n);
for (int i = 0; i < n; i++)
{
    hash[i] = i;
    for (int j = 0; j < i; j++)
    {
        if (arr[i]%arr[j]==0 && 1 + dp[j] > dp[i])
        {
            dp[i] = 1 + dp[j];
            hash[i] = j;
        }
    }
    if (dp[i] > maxi)
    {
        maxi = dp[i];
        last = i;
    }
}
vector<int> temp;
temp.push_back(arr[last]);
while (hash[last] != last)
{
    last = hash[last];
    temp.push_back(arr[last]);
}
reverse(temp.begin(), temp.end());
return temp;
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

    vector<int> x = printlcs(arr, n);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
    }
}