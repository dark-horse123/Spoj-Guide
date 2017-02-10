#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int sum[105][105];
int p[105];
int matrix(int i,int j)
{
    if(i==j)
        return dp[i][j]=0;
    if(j==i+1)
        return dp[i][j]=p[i]*p[j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int k,count;
    int min1=10000000;
    for(k=i;k<j;k++)
    {
        count=matrix(i,k)+matrix(k+1,j)+sum[i][k]*sum[k+1][j];
        min1=min(min1,count);
    }
    dp[i][j]=min1;
    return min1;
}
int main()
{
    int i,j,n;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<105;i++)
            for(j=0;j<105;j++)
                dp[i][j]=-1;

        for(i=0;i<n;i++)
            scanf("%d",&p[i]);

        for(i = 0;i<n;++i)
            sum[i][i] =p[i];

        for(i = 0;i < n;++i)
            for(j = i+1;j < n;++j)
                sum[i][j] =(sum[i][j-1]+p[j])%100;

        cout<<matrix(0,n-1)<<endl;
    }
}

