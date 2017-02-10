#include<bits/stdc++.h>
using namespace std;
int d,n,k,a[10000],dp[55][55];
int check(int i,int op)
{
    if(op<0)
        return dp[i][op]=0;
    if(i==2*n)
    {
        if(op!=0)
            return dp[i][op]=0;
        if(op==0)
            return dp[i][op]=1;
    }
    if(dp[i][op]!=-1)
        return dp[i][op];
    int count;
    if(a[i]==1)
    {
        op++;
        count=check(i+1,op);
    }
    else if(a[i]==-1)
        count=check(i+1,op+1)+check(i+1,op-1);
    return dp[i][op]=count;
}
int main()
{
    int t,i,j,op=0,cl=0;
    scanf("%d",&d);
    while(d--)
    {
        for(i=0;i<55;i++)
            for(int j=0;j<55;j++)
                dp[i][j]=-1;
        op=0;cl=0;
        for(i=0;i<1000;i++)
            a[i]=-1;
        scanf("%d %d",&n,&k);
        for(i=0;i<k;i++)
        {
            scanf("%d",&t);
            a[t-1]=1;
        }
        cout<<check(0,0)<<endl;
    }
}
