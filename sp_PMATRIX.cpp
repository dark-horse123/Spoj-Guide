#include<bits/stdc++.h>
using namespace std;
vector <int> adj[20005];
vector <int> rev_adj[20005];
stack <int> stack1;
map<int,int> map1;int cnt1=0;
int v[20005];
void dfs(int i)
{
    v[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(v[adj[i][j]]==0)
        {
            dfs(adj[i][j]);
        }
    }
    stack1.push(i);
}
void rev_dfs(int i)
{
    v[i]=1;map1[i]=cnt1;
    for(int j=0;j<rev_adj[i].size();j++)
    {
        if(v[rev_adj[i][j]]==0)
        {
            rev_dfs(rev_adj[i][j]);
        }
    }
}
int main()
{
    int n,e,i,a,b,t,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&e);
        cnt1=0;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            rev_adj[i].clear();
        }
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            rev_adj[b].push_back(a);
        }
        memset(v,0,sizeof(v));
        for(i=1;i<=n;i++)
        {
            if(v[i]==1)
                continue;
            dfs(i);
        }
        for(i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                stack1.push(i);
                v[i]==1;
            }
        }
        memset(v,0,sizeof(v));int temp,flag=0;cnt1=0;
        map1.clear();
        while(!stack1.empty())
        {
            temp=stack1.top();
            stack1.pop();
            if(v[temp]==0)
            {
                cnt1++;
                rev_dfs(temp);
            }
        }
        int in[20005]={0},out[20005]={0},out0=0,in0=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                if(map1[i]!=map1[adj[i][j]])
                {
                    out[map1[i]]++;
                    in[map1[adj[i][j]]]++;
                }
            }
        }
        for(i=1;i<=cnt1;i++)
        {
            if(in[i]==0&&cnt1!=1)
                in0++;
            if(out[i]==0&&cnt1!=1)
                out0++;
        }
        printf("%d\n",max(in0,out0));
    }
}
