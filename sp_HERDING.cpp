#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1002][1002];
int parent[1002][1002];
int size[1002][1002],v[1002][1002];
void initialize()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            parent[i][j]=i*n+j;
            size[i][j]=1;
        }
    }
}
void union1(int i1,int j1,int i2,int j2)
{

}
void root(int i,int j)
{

}
void dsu(int i,int j)
{
    int i1,j1;
    while(1)
    {
        if()
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    memset(v,0,sizeof(v));
    initialize();
    int i,j;
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(!v[i][j])
                dsu(i,j);
        }
    }
}
