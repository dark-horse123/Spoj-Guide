#include<bits/stdc++.h>
using namespace std;
//#define lli long long int
//#define pii pair<int,int>
int t,n,time1[55][55],cost[55][55],dp[55][1003];
int inf=(int) 1e9;
int main()
{
    int i,j,k;
    while(cin>>n>>t&&n!=0&&t!=0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&time1[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&cost[i][j]);
        dp[0][0]=0;
        for(i=1;i<=n;i++)
            dp[i][0]=inf;
        int ind;
        for(k=1;k<=t;k++)
        {
            for(i=0;i<n;i++)
            {
                dp[i][k]=dp[i][k-1];
                for(j=0;j<n;j++)
                {
                    if(k<time1[j][i])
                        continue;
                    else
                        dp[i][k]=min(dp[i][k],dp[j][k-time1[j][i]]+cost[j][i]);
                }
            }
            if(dp[n-1][k]!=dp[n-1][k-1])
                ind=k;
        }
        cout<<dp[n-1][ind]<<" "<<ind<<endl;
    }
}
