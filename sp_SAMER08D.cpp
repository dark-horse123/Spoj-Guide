#include<bits/stdc++.h>
using namespace std;
int k,l1,l2;
char s1[1002],s2[1002];int dp[1002][1002][102];
int lcs(int i,int j,int k1)
{
    if(i==0||j==0)
        return 0;
    if(dp[i][j][k1]!=-1)
        return dp[i][j][k1];
    if(s1[i-1]==s2[j-1])
    {
        if(k1==k-1)
            return dp[i][j][k1]=k+lcs(i-1,j-1,k1+1);
        else if(k1>=k)
            return dp[i][j][k1]=1+lcs(i-1,j-1,k1+1);
        else
            return dp[i][j][k1]=max(lcs(i-1,j-1,k1+1),max(lcs(i-1,j,0),lcs(i,j-1,0)));
    }
    else if(s1[i-1]!=s2[j-1])
        return dp[i][j][k1]=max(lcs(i-1,j,0),lcs(i,j-1,0));
}
int main()
{
    while(1)
    {
        scanf("%d",&k);
        if(k==0)
            break;
        scanf("%s",s1);
        scanf("%s",s2);
        l1=strlen(s1);
        l2=strlen(s2);
        for(int i=0;i<=l1;i++)
            for(int j=0;j<=l2;j++)
                for(int k=0;k<=102;k++)
                    dp[i][j][k]=-1;
        printf("%d\n",lcs(l1,l2,0));
    }
}
