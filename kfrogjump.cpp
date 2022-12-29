#include <bits/stdc++.h>
using namespace std;
int kfrogjump(vector<int> x, int n,int k)
{
    if (n == 0)
    {
        return 0;
    }
    int minsteps=INT_MAX;
    int energyone;
    for (int i = 1; i <=k; i++)
    {  if(n-i>=0)
        energyone = kfrogjump(x, n - i,k) + abs(x[n] - x[n - i]); 
       minsteps=min(minsteps,energyone);
    }
    return minsteps;
}
// tc=>o(n)*k
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x[i] = a;
    }
    int k;
    cin>>k;
    cout << kfrogjump( x,n-1,k);
}