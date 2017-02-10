#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];int vis[100005];
int cnt=0,u,v,ans=0;
void bfs1(int a)
{
    queue<int> q;int i,d;
    q.push(a);
    vis[a]=1;
    while(!q.empty())
    {
        int t=q.front();
        for(i=0;i<adj[t].size();i++)
        {
            if(vis[adj[t][i]]==0)
            {
                q.push(adj[t][i]);vis[adj[t][i]]=1;
            }
        }
        if(q.size()==1)
            {u=t;}
        q.pop();
    }
}
void dfs(int i,int l)
{
    vis[i]=1;
    int j;
    for(j=0;j<adj[i].size();j++)
    {
        if(vis[adj[i][j]]==0)
        {
            dfs(adj[i][j],l+1);
        }
    }
    ans=max(ans,l);
}
int main()
{
    int t,i,n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);ans=0;cnt=0;
        for(i=0;i<n;i++)
            adj[i].clear();
        for(i=1;i<=n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        bfs1(0);
        memset(vis,0,sizeof(vis));
        dfs(u,0);
        if(ans%2==0)
            printf("%d\n",ans/2);
        else
            printf("%d\n",(ans+1)/2);
    }
}
