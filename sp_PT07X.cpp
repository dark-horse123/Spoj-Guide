#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100004];
int dp[100004][2];
int min_sum(int node,int parent,bool p_incl)
{
    int ans=0,ans1=1,i;
    if(dp[node][p_incl]!=-1)
        return dp[node][p_incl];
    if(p_incl)
    {
        for(i=0;i<adj[node].size();i++)
            if(adj[node][i]!=parent)
                ans=ans+min_sum(adj[node][i],node,false);
        for(i=0;i<adj[node].size();i++)
            if(adj[node][i]!=parent)
                ans1=ans1+min_sum(adj[node][i],node,true);
        return dp[node][p_incl]=min(ans,ans1);
    }
    else
    {
        ans1=1;
        for(i=0;i<adj[node].size();i++)
            if(adj[node][i]!=parent)
                ans1=ans1+min_sum(adj[node][i],node,true);
        return dp[node][p_incl]=ans1;
    }
}
int main()
{
    int n,i,a,b,ans1,ans2;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //memset(visited,0,sizeof(visited));
    //memset(l_size,0,sizeof(l_size));
    memset(dp,-1,sizeof(dp));
    ans1=1;ans2=0;
    for(i=0;i<adj[1].size();i++)
        ans1=ans1+min_sum(adj[1][i],1,true);
    for(i=0;i<adj[1].size();i++)
        ans2=ans2+min_sum(adj[1][i],1,false);
    printf("%d\n",min(ans1,ans2));
    //printf("%d\n",ans.size());
}
