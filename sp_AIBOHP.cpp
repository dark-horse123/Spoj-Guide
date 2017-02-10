#include<bits/stdc++.h>
using namespace std;
unsigned short int t,ans;
static unsigned short int dp[6102][6102];
char s1[6102],s2[6102];
unsigned short int max(unsigned short int i,unsigned short int j)
{
    return (i>j)?i:j;
}
int main()
{
    unsigned short int i,j;
    scanf("%hu",&t);
    while(t--)
    {
        scanf("%s",s1);
        unsigned short int l1,l2;
        l1=strlen(s1);
        for(i=0;i<l1;i++)
        {
            s2[i]=s1[l1-i-1];
        }
        for(i=0;i<=l1;i++)
        {
            for(j=0;j<=l1;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else if(s1[i-1]!=s2[j-1])
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        ans=l1-dp[l1][l1];
        printf("%hu\n",ans);
    }
}
