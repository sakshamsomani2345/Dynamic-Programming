#include <bits/stdc++.h>
using namespace std;
int mincoins(int *arr, int n, int k)
{
    if (n == 0)
    {
        if(k%arr[0]==0) return k/arr[0];
        return 1e9;
    }
    int x=INT_MAX;
    if (k >= arr[n])
    {
     x = 1+mincoins(arr, n, k - arr[n]);
    }
    int y = mincoins(arr, n-1 , k);
    return min(x, y);
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

    int k;
    cin >> k;
    cout << mincoins(arr, n-1, k);
}