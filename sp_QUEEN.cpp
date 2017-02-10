#include<bits/stdc++.h>
using namespace std;
struct node{
int cell;
int dir;
};
typedef struct node node;
vector<int> adj[1005];bool v[1000002];int n,m,dist[1000002];
int st_ind,end_ind;
void bfs2(int i)
{
    queue<node> q;
    node t;t.cell=i;t.dir=-5;
    q.push(t);dist[i]=0;int dir1;
    while(!q.empty())
    {
        t=q.front();q.pop();node t1;
        for(int j=0;j<adj[t.cell].size();j++)
        {
            if(adj[t.cell][j]==t.cell-m)
                t1.dir=4;
            else if(adj[t.cell][j]==t.cell+m)
                t1.dir=-4;
            else if(adj[t.cell][j]==t.cell-m-1)
                t1.dir=-1;
            else if(adj[t.cell][j]==t.cell+m+1)
                t1.dir=1;
            else if(adj[t.cell][j]==t.cell-m+1)
                t1.dir=3;
            else if(adj[t.cell][j]==t.cell+m-1)
                t1.dir=-3;
            else if(adj[t.cell][j]==t.cell-1)
                t1.dir=-2;
            else if(adj[t.cell][j]==t.cell+1)
                t1.dir=2;
            if(t.dir+t1.dir==0)
                continue;
            if(t.dir==t1.dir)
            {
                if(dist[adj[t.cell][j]]>dist[t.cell])
                {
                    dist[adj[t.cell][j]]=dist[t.cell];
                    t1.cell=adj[t.cell][j];
                    q.push(t1);
                }
            }
            else
            {
                if(dist[adj[t.cell][j]]>=dist[t.cell]+1)
                {
                    dist[adj[t.cell][j]]=dist[t.cell]+1;
                    t1.cell=adj[t.cell][j];
                    q.push(t1);
                }
            }
        }
    }
}
int main()
{
     char s[1005][1005];int t,i,j,i1,j1;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d%d",&n,&m);memset(v,0,sizeof(v));
         for(i=0;i<1000002;i++)
            dist[i]=1000000;
         for(i=0;i<=n*m+10;i++)
            adj[i].clear();
         for(i=0;i<n;i++)
         {
             scanf("%s",s[i]);
             for(j=0;j<m;j++)
             {
                 if(s[i][j]=='S')
                    st_ind=m*(i)+j+1;
                 else if(s[i][j]=='F')
                    end_ind=m*(i)+j+1;
             }
         }
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                if(s[i][j]=='X')
                {
                    continue;
                }
                 for(i1=-1;i1<=1;i1++)
                 {
                     if(i+i1<0||i+i1>n-1)
                        continue;
                     for(j1=-1;j1<=1;j1++)
                     {
                         if(j+j1<0||j+j1>m-1||(i+i1==i&&j+j1==j))
                            continue;
                         if(s[i+i1][j+j1]!='X')
                            adj[i*m+j+1].push_back((i+i1)*m+j+j1+1);
                     }
                 }
             }
         }
         bfs2(st_ind);
         if(dist[end_ind]!=1000000)
            printf("%d\n",dist[end_ind]);
         else
            printf("-1\n");
     }
}
