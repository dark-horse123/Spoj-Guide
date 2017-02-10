#include<bits/stdc++.h>
using namespace std;
int k,l1,l2;
char s1[1002],s2[1002];int dp[1002][1002];
int len[1002][1002];
int lcs(int l1,int l2,int k)
{
    int i,j;
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            len[i][j]=0;
            if(s1[i-1]==s2[j-1])
            {
                len[i][j]=len[i-1][j-1]+1;
                if(len[i][j]>=k)
                {
                    for(int g=k;g<=len[i][j];g++)
                        dp[i][j]=max(dp[i][j],dp[i-g][j-g]+g);
                }
            }
        }
    }
    return dp[l1][l2];
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
        printf("%d\n",lcs(l1,l2,k));
    }
}
