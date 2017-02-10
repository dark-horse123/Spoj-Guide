#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100000];
int v[100000],n,m,a,b,k=0;
void dfs(int i)
{
    v[i]=1;
    k++;
    for(int j=0;j<adj[i].size();j++)
    {
        if(v[adj[i][j]]==0)
        {
            dfs(adj[i][j]);
        }
    }
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++)
    {
        k=0;
        dfs(i);
        memset(v,0,sizeof(v));
        if(k==n)
            printf("%d ",i);
    }
    return 0;
}
