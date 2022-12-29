#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m)
{
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (s1[n] == s2[m])
    {
         return 1 + lcs(s1, s2, n - 1, m - 1);
    }
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}
int main()
{
    string s1;
    cin >> s1;
    string s2=s1;
     reverse(s1.begin(), s1.end());
    cout << lcs(s1,s2, s1.size() - 1, s1.size() - 1);
}