#include<bits/stdc++.h>
using namespace std;
long long int t;
long long int i,N,k;
long long int dp[105][105][2];
long long int countStrings(long long int n)
{
    if(n==1&&n!=N)
        return 1;
    else if(n==N)
        n=n;
    else n--;
    long long int a[n], b[n];
    a[0] = b[0] = 1;
    for (long long int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}
long long int adjacent(long long int prev,long long int n,long long int k)
{
    if(n==0&&k==0)
        return dp[n][k][prev]=1;
    if(n==0&&k>0)
        return dp[n][k][prev]=0;
    if(dp[n][k][prev]!=-1)
        return dp[n][k][prev];
    if(k==0)
        return dp[n][k][prev]=countStrings(n);
    if(prev==0)
        return dp[n][k][prev]=adjacent(1,n-1,k)+adjacent(0,n-1,k);
    return dp[n][k][prev]=adjacent(1,n-1,k-1)+adjacent(0,n-1,k);
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld %lld %lld",&i,&N,&k);
        /*if(k==0)
            prlong long intf("%d %d",i,)*/
        printf("%lld %lld\n",i,adjacent(0,N,k));
    }
}
