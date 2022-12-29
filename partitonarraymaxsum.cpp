#include <bits/stdc++.h>
using namespace std;
int maxsum(int *arr,int i,int n,int k){
    if(i==n){
        return 0;
    }
    int len=0;
    int maxi=INT_MIN;
    int maxans=INT_MIN;
for (int j = i; j < min(n,i+k); j++)
{
len++;
maxi=max(maxi,arr[j]);
int sum=len*maxi+maxsum(arr,j+1,n,k);
maxans=max(maxans,sum);
}
return maxans;

}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  int k;
  cin>>k;
  
    cout << maxsum(arr,0,n,k);
}