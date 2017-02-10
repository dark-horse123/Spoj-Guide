#include<bits/stdc++.h>
using namespace std;
struct node{
    int i,d;
};
typedef struct node node;
int v[50005],d[50005],n,a,b;
vector<node> adj[50005];
int bfs(int s)
{
    queue<int> q;
    int i,t;
    q.push(s);
    for(i=0;i<=n+1;i++)
    {
        d[i]=0;
        v[i]=0;
    }
    v[s]=1;
    while(!q.empty())
    {
        t=q.front();
        //cout<<t<<" "<<adj[t].size()<<"\n";
        for(i=0;i<adj[t].size();i++)
        {
            //printf("%d %d\n",v[adj[t][i].i],adj[t][i].d);
            if(v[adj[t][i].i]==0)
            {
                q.push(adj[t][i].i);
                v[adj[t][i].i]=1;
                d[adj[t][i].i]+=d[t]+adj[t][i].d;
            }
        }
        q.pop();
    }
    int max=0;
    for(i=1;i<=n;i++)
    {
        if(d[max]<d[i])
            max=i;
    }
    return max;
}
int main()
{
    int t,i,d1;
    node temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&d1);
            temp.i=b;
            temp.d=d1;
            adj[a].push_back(temp);
            temp.i=a;
            adj[b].push_back(temp);
        }
        int a=(bfs(1));
        //printf("%d\n",d[a]);
        int b=(bfs(a));
        printf("%d\n",d[b]);
    }
    return 0;
}
