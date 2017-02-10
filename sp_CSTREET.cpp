#include<bits/stdc++.h>
using namespace std;
long long int size[1005],parent[1005];
pair<long long int,pair<long long int,long long int> > pr[300002];
long long int t,p,n,m;
long long int root(long long int a)
{
    while(parent[a]!=a)
        a=parent[a];
    return a;
}
void initialize(long long int e)
{
    for(long long int i=1;i<=e;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}
void Union(long long int a,long long int b)
{
    long long int root_a=root(a);
    long long int root_b=root(b);
    if(size[root_a]>=size[root_b])
    {
        parent[root_b]=root_a;
        size[root_a]+=size[root_b];
    }
    else
    {
        parent[root_a]=root_b;
        size[root_b]+=size[root_a];
    }
}
long long int kruskal()
{
    long long int x,y,cost=0;
    for(long long int i=0;i<m;i++)
    {
        x=pr[i].second.first;
        y=pr[i].second.second;
        if(root(x)!=root(y))
        {
            cost=cost+pr[i].first;
            Union(x,y);
        }
    }
    return cost;
}
int main()
{
    long long int i,a,b,c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&p,&n,&m);
        initialize(n);
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            pr[i]=make_pair(c,make_pair(a,b));
        }
        sort(pr,pr+m);
        long long int min_cost=kruskal();
        printf("%lld\n",p*min_cost);
    }
}
