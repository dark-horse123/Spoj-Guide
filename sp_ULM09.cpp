#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int> > adj[200004];
bool mst_set[200004];
long long int key[200004];
long long int ans=0,n,ind=10000000000;
vector<long long int> mst;
long long int find_min()
{
    long long int i,min1=1000000005,v;
    for(i=ind;i<=n;i++)
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
    long long int i;
    while(mst.size()!=n)
    {
        long long int k=find_min();
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
    long long int i,j,m,a,b,w;
    long long int ans1=0;
    while(1)
    {
        ind=10000000000;
        ans=0;ans1=0;
        cin>>n>>m;
        if(n==m&&n==0)
            break;
        for(i=0;i<=n+4;i++)
            adj[i].clear();
        mst.clear();
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>w;
            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
            ind=min(ind,min(a,b));
            ans1=ans1+w;
        }
        for(i=ind+1;i<n+4;i++)
        {
            mst_set[i]=0;
            key[i]=1000000005;
        }
        key[ind]=0;
        mst_set[ind]=0;
        create_mst();
        cout<<ans1-ans<<"\n";
    }
    return 0;
}

