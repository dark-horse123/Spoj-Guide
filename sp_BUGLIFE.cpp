#include<bits/stdc++.h>
using namespace std;
vector<int> adj[2005];
int b,n;int t,t1=1;
char v[2005];
void dfs(int i,int prev)
{
    if(prev==-1)
    {
        v[i]='M';
    }
    else
    {
        if(v[prev]=='M')
            v[i]='F';
        else if(v[prev]=='F')
            v[i]='M';
    }
    for(int j=0;j<adj[i].size();j++)
    {
        if(v[adj[i][j]]=='\0')
        {
            prev=i;
            dfs(adj[i][j],prev);
        }
    }
}
int check(int i)
{
    for(int j=0;j<adj[i].size();j++)
    {
        if(v[i]==v[adj[i][j]])
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",t1);
            return 1;
        }
    }
    return 10;
}
int main()
{
    int i,i1,i2;
    int k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&b,&n);
        k=10;
        memset(v,'\0',sizeof(v));
        for(i=1;i<=b;i++)
        {
            adj[i].clear();
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&i1,&i2);
            adj[i1].push_back(i2);
            adj[i2].push_back(i1);
        }
        for(i=1;i<=b;i++)
        {
            if(v[i]=='\0')
                dfs(i,-1);
        }
        for(i=1;i<=b;i++)
        {
            k=check(i);
            if(k==1)
                break;
        }
        if(k==10)
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",t1);
        }
        t1++;
    }
    return 0;
}
