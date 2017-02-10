#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[10004];
bool mst_set[10004];
int key[10004];
long long int ans=0,n;
vector<int> mst;
int find_min()
{
    int i,min1=1000005,v;
    for(i=1;i<=n;i++)
    {
        if(mst_set[i]==0&&key[i]<min1)
        {
            min1=key[i];
            v=i;
        }
    }
    ans=ans+min1;
    return v;
}
void create_mst()
{
    int i;
    while(mst.size()!=n)
    {
        int k=find_min();
        mst.push_back(k);
        mst_set[k]=1;
        for(i=0;i<adj[k].size();i++)
        {
            if(adj[k][i].second<key[adj[k][i].first])
                key[adj[k][i].first]=adj[k][i].second;
        }
    }
}
int main()
{
    int i,j,m,a,b,w;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    memset(mst_set,0,sizeof(mst_set));
    for(i=2;i<=n;i++)
        key[i]=1000005;
    key[1]=0;
    create_mst();
    cout<<ans<<"\n";
    return 0;
}
