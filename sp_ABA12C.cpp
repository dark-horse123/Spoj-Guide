#include<bits/stdc++.h>
using namespace std;
int a[105],dp[105];
int max(int a,int b)
{
    return (a>b)?a:b;
}
int cost(int k)
{
    if(k==0)
        return 0;
    if(dp[k]!=-1)
        return dp[k];
    int ans=10000000;
    for(int i=1;i<=k;i++)
    {
        if(a[i]<0)
            continue;
        ans=min(ans,a[i]+cost(k-i));
        dp[k-i]=ans;
    }
    return ans;
}
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        int ans1=cost(k);
        if(ans1!=10000000)
            printf("%d\n",ans1);
        else
            printf("-1\n");
    }
}
