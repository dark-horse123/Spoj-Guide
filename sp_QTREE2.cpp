#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int p;
    int d;
};
typedef struct node node;
bool visited[10005];
vector<node> adj[10005];
int dist[10005];
vector<int> inorder;
vector<int> postorer;
void find_dist(int n,int di)
{
    visited[n]=1;
    int i;
    for(i=0;i<adj[n].size();i++)
    {
        if(!visited[adj[n][i].p])
        {
            dist[adj[n][i].p]=di+adj[n][i].d;
            find_dist(adj[n][i].p,dist[adj[n][i].p]);
        }
    }
}
void inorder_t(int n)
{
    if(adj[n].size()==0)
        return;
    if(adj[n].size()==1)
    {
        inorder_t(adj[n][0].p);
        inorder.push_back(n);
    }
    else if(adj[n].size()==2)
    {
        inorder_t(adj[n][0].p);
        inorder.push_back(n);
        inorder_t(adj[n][1].p);
    }
}
void preorder_t()
{

}
int main()
{
    int t,i,a,b,c;
    char s[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n-1;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            node temp;
            temp.p=b;
            temp.d=c;
            adj[a].push_back(temp);
            temp.p=a;
            adj[b].push_back(temp);
        }
        dist[1]=0;
        find_dist(1,0);
        inorder_t(1);
        postorder_t(1);
        for(i=1;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
//        find_lca();
    }
}
