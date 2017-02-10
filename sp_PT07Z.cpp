#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10004];
int dist[10004],n,visited[10004];
int dfs(int u)
{
    int i;
    visited[u]=1;
    for(i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
            dist[adj[u][i]]=dist[u]+1;
            dfs(adj[u][i]);
        }
    }
}
int main()
{
    int i,u,v;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[1]=0;
    dfs(1);int ind=1,ans1=dist[1];
    for(i=2;i<=n;i++)
    {
        if(dist[i]>ans1)
        {
            ans1=dist[i];
            ind=i;
        }
    }
    memset(dist,0,sizeof(dist));
    memset(visited,0,sizeof(visited));
    dfs(ind);
    ind=1,ans1=dist[1];
    for(i=2;i<=n;i++)
    {
        ans1=max(ans1,dist[i]);
    }
    printf("%d\n",ans1);
}
