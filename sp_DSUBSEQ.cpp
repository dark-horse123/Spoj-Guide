#include<bits/stdc++.h>
using namespace std;
string s;long long int i,dp[100005],last[26],m=1000000007;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        memset(last,-1,sizeof(last));
        int l=s.length();
        dp[0]=1;last[s[0]-'A']=0;
        for(i=1;i<=l;i++)
        {
            dp[i]=(dp[i-1]*2)%m;
            if(last[s[i-1]-'A']!=-1)
                dp[i]=(dp[i]-dp[last[s[i-1]-'A']-1]+m)%m;
            last[s[i-1]-'A']=i;
        }
        printf("%d\n",dp[l]);
    }
}
