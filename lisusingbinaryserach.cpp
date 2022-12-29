#include <bits/stdc++.h>
using namespace std;
int lcs(int *arr,int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }else{
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[index]=arr[i];
        }
    }
   return temp.size(); 
}
// tc=O(nlogn)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << lcs(arr, n);
}