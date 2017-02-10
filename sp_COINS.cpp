#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> dp;
long long int change(long long int n)
{
    if(dp[n]!=0)
        return dp[n];
    if(n>=(n/2+n/3+n/4))
        return n;
    long long int s=max(n,n/2+n/3+n/4);
    s=max(s,change(n/2)+change(n/3)+change(n/4));
    dp[n]=s;
    return dp[n];
}
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
        printf("%lld\n",change(n));
    return 0;
}
