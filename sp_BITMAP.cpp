#include<bits/stdc++.h>
using namespace std;
int adj[200][200];
int dist[200][200],n,m;
vector<pair<int,int> > white;
queue<pair<int,int> >q;
char s[200];
void check(int i1,int j1,int i,int j)
{
    if(i1>0&&i1<=n&&j1>0&&j1<=m)
    {
        if(dist[i1][j1]>dist[i][j]+1)
        {
            dist[i1][j1]=dist[i][j]+1;
            q.push(make_pair(i1,j1));
        }
    }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                dist[i][j]=1000000;
        white.clear();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            for(j=1;j<=m;j++)
            {
                adj[i][j]=s[j-1]-'0';
                if(adj[i][j]==1)
                {
                    dist[i][j]=0;
                    white.push_back(make_pair(i,j));
                }
            }
        }
        int i1,j1,k;
        for(k=0;k<white.size();k++)
        {
            q.push(make_pair(white[k].first,white[k].second));
            while(!q.empty())
            {
                i=q.front().first;j=q.front().second;
                q.pop();
                i1=i-1,j1=j;
                check(i1,j1,i,j);
                i1=i;j1=j-1;
                check(i1,j1,i,j);
                i1=i+1;j1=j;
                check(i1,j1,i,j);
                i1=i;j1=j+1;
                check(i1,j1,i,j);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }
    }
}
