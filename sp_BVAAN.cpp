#include<bits/stdc++.h>
using namespace std;
char s1[102],s2[102];
int l1,l2,t,k;
int dp[102][102][102],dp1[102][102];
int check_lcs(int l1,int l2)
{
    if(dp1[l1][l2]!=-1)
        return dp1[l1][l2];
    if(l1==0||l2==0)
        dp1[l1][l2]=0;
    else if(s1[l1-1]==s2[l2-1])
        dp1[l1][l2]=1+check_lcs(l1-1,l2-1);
    else
        dp1[l1][l2]=max(check_lcs(l1,l2-1),check_lcs(l1-1,l2));
    return dp1[l1][l2];
}
int lcs(int i,int j,int k1)
{
    if(i==0||j==0)
        return dp[i][j][k1]=0;
    if(dp[i][j][k1]!=-1)
        return dp[i][j][k1];
    if(s1[i-1]==s2[j-1])
    {
        if(k1==k-1)
        {
            int count;
            count=max(s1[i-1]+0,lcs(i-1,j-1,k1));
            return dp[i][j][k1]=count;
        }
        return dp[i][j][k1]=max(s1[i-1]+lcs(i-1,j-1,k1+1),lcs(i-1,j-1,k1));
    }
    else if(s1[i-1]!=s2[j-1])
        return dp[i][j][k1]=max(lcs(i-1,j,k1),lcs(i,j-1,k1));
}
int main()
{

    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%d",&k);
        l1=strlen(s1);
        l2=strlen(s2);
        if(check_lcs(l1,l2)>=k)
            printf("%d\n",lcs(l1,l2,0));
        else printf("0\n");
    }
}

