#include<bits/stdc++.h>
using namespace std;
map<string,long long int> m1;
vector<pair<long long int,long long int> >adj[10004];
struct cmp
{
    bool operator()(const pair<int , int> &a , const pair<int , int> &b){
        return a.first > b.first;
    }
};
int main()
{
    long long int t,n,i,p,j,cost,nr,r;
    string s,s1,s2;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            scanf("%lld",&p);
            m1[s]=i;
            for(j=1;j<=p;j++)
            {
                scanf("%lld %lld",&nr,&cost);
                adj[i].push_back(make_pair(nr,cost));
                adj[nr].push_back(make_pair(i,cost));
            }
        }
        scanf("%lld",&r);
        for(i=1;i<=r;i++)
        {
            cin>>s1>>s2;
            int source=m1[s1],dest=m1[s2];
            long long int dist[n+9];
            fill(dist , dist+n , INT_MAX-100000);
            priority_queue<pair<long long int,long long int> , vector<pair<long long int,long long int> >, cmp > q;
            dist[m1[s1]]=0;
            q.push(make_pair(0,m1[s1]));
            long long int j;
            while(!q.empty())
            {
                int wt = q.top().first;
                int node =q.top().second;
                q.pop();
                if(node == dest)
                {
                    printf("%lld\n",wt);
                    break;
                }
                for(j=0;j<adj[node].size();j++)
                {
                    if(dist[adj[node][j].first] > dist[node] + adj[node][j].second)
                    {
                        dist[adj[node][j].first] = dist[node]+adj[node][j].second;
                        q.push(make_pair(dist[adj[node][j].first],adj[node][j].first));
                    }
                }
            }
            /*while(!q.empty())
            {
                pair<long long int,long long int> temp=q.top();
                if(temp.second==m1[s2])
                {
                    printf("%lld\n",temp.first);
                    break;
                }
                q.pop();
                for(j=0;j<adj[temp.second].size();j++)
                {
                    if(dist[adj[temp.second][j].first]>dist[temp.second]+adj[temp.second][j].second)
                    {
                        dist[adj[temp.second][j].first]=dist[temp.second]+adj[temp.second][j].second;
                        q.push(make_pair(dist[adj[temp.second][j].first],adj[temp.second][j].first));
                    }
                }
            }*/
        }
    }
}
