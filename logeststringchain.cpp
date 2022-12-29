#include <bits/stdc++.h>
using namespace std;
bool check(string a ,string b){
    if(a.size()!=b.size()+1){
        return false;
    }
    int first=0;
    int second=0;
    while (first<a.size())
    {
        if(a[first]==b[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first==a.size() && second==b.size()){
        return true;
    }else{
        return false;
    }
}
bool comp(string a ,string b){
    return a.size()<b.size();
}
int lsc(vector<string> arr, int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    sort(arr.begin(),arr.end(),comp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ( check(arr[i],arr[j])&& 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    
    cout<<lsc(arr,n);
}