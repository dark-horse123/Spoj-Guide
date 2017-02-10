#include<bits/stdc++.h>
using namespace std;
vector<int> adj[50005];int d[50005];
int n,k,ans=10000,cnt=0;
void bfs(int i)
{
    queue<int> q;
    q.push(i);
    int t1,j,p,p1,temp;d[i]=0;
    while(!q.empty())
    {
        t1=q.front();
        for(j=0;j<adj[t1].size();j++)
        {
            int temp2=d[t1];
            temp=abs(adj[t1][j]-t1);

                if(t1!=1)
                {
                    p=temp2/temp;p1=temp2%temp;
                    if(p%2==0&&temp2%temp!=0)
                    {
                        temp2+=(temp-p1)+temp;
                    }
                    else if(p%2!=0)
                    {
                        temp2+=(temp-p1);
                    }
                }

            temp2+=abs(adj[t1][j]-t1);
            if(temp2<d[adj[t1][j]])
            {
                d[adj[t1][j]]=temp2;
                q.push(adj[t1][j]);
            }
        }
        q.pop();
    }
}
int main()
{
    scanf("%d%d",&k,&n);int i,a,b;
    for(i=0;i<k+5;i++)
        d[i]=100005;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    printf("%d\n",d[k]*5);
}
