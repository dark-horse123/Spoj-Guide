#include<bits/stdc++.h>
using namespace std;
long long int t,n;
long long int likes[25][25],dp[1<<20];
long long int assignment(long long int mask)
{
    if(__builtin_popcount(mask)==n)
        return dp[mask]=1;
    /*if(dp[i][cnt]!=-1&&j>=0)
        return dp[i][cnt];*/
    if(dp[mask]!=-1)
        return dp[mask];
    long long int i1;
    long long int ans=0,ch_cnt=0;
    for(i1=0;i1<n;i1++)
    {
        if(likes[__builtin_popcount(mask)][i1]==1&&(mask&(1<<i1))==0)
            ans=ans+assignment(mask|(1<<i1));
    }
    return dp[mask]=ans;
}
int main()
{
    long long int i,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&likes[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",assignment(0));
    }
}
/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1*/
