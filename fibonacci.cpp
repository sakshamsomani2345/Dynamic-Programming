#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int memo(int n,int arr[]){
  if(n==0 || n==1){
        return n;
    }  
   if(arr[n]!=-1){
    return arr[n];
   } 
   arr[n]=memo(n-1,arr)+memo(n-2,arr);
   return arr[n];

}
int dp(int n){
    int arr[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }
return memo(n,arr);
    
}
// sc=>o(n)
// tc=>o(n)+o(n)
int tabular(int n){
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for (int i = 2; i < n+1; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
    
}
// sc=>o(n)
// tc=>o(n)
int optimised(int n){
    int prev2=0;
    int prev=1;
    for (int i = 2; i < n+1; i++)
    {
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
    
}
// sc=>o(n)
// tc=>o(1)
int main(){
cout<<optimised(5);
}