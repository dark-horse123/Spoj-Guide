#include<bits/stdc++.h>
using namespace std;
int B[505][505];
int Y[505][505];
int dp[505][505];
int n,m;
int cost(int i,int j)
{
    int x,y,sum_b=0,sum_y=0;
    if(i<0||j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==0&&j==0)
        return dp[i][j]= max(B[0][0],Y[0][0]);
    for(x=j;x>=0;x--)
        sum_y=sum_y+Y[i][x];
    for(y=i;y>=0;y--)
        sum_b=sum_b+B[y][j];
    return dp[i][j]=max(sum_y+cost(i-1,j),sum_b+cost(i,j-1));
}
int main()
{
    int i,j;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
        for(i=0;i<505;i++)
            for(j=0;j<505;j++)
            dp[i][j]=-1;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>Y[i][j];
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>B[i][j];
        cout<<cost(n-1,m-1)<<endl;
        cin>>n>>m;
    }
}
