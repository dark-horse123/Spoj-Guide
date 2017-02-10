#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[10004],n,dp[10004][2];
int main()
{
    lli k,i,t,ans;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        if(n==0)
            printf("Case %lld: 0\n",k);
        else if(n==1)
            printf("Case %lld: %lld\n",k,a[1]);
        else
        {
            dp[n][0]=a[n];dp[n][1]=0;
            for(i=n-1;i>=1;i--)
            {
                dp[i][0]=max(a[i]+dp[i+1][1],dp[i+1][0]);
                dp[i][1]=dp[i+1][0];
            }
            ans=max(dp[1][0],dp[1][1]);
            printf("Case %lld: %lld\n",k,ans);
        }
    }
}
