#include <bits/stdc++.h>
using namespace std;
int cutroad(int *arr,int n,int N){
    int notake=cutroad(arr,n-1,N);
    int take=INT_MAX;
    if(n+1<=N)
    take=arr[n]+cutroad(arr,n,N-n-1);
    return max(take,notake);
}
int main()
{
    int n;
s    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;
    cout << cutroad(arr,n-1,n);
}