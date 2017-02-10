#include<bits/stdc++.h>
using namespace std;
int size1[20004],parent[20004];
void initialize()
{
    int i;
    for(i=0;i<=20004;i++)
    {
        parent[i]=i;
        size1[i]=1;
    }
}
int root(int a)
{
    while(parent[a]!=a)
    {
        a=parent[a];
    }
    return a;
}
int check(int a,int b)
{
    if(root(a)==root(b))
        return 1;
    return 0;
}
void union1(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);
    if(size1[root_a]>=size1[root_b])
    {
        parent[root_b]=root_a;
        size1[root_a]=size1[root_a]+size1[root_b];
    }
    else
    {
        parent[root_a]=root_b;
        size1[root_b]=size1[root_b]+size1[root_a];
    }
}
int main()
{
    int n,m,i,a,b;
    initialize();
    cin>>n>>m;
    int ch=0;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        if(ch==0)
        {
            ch=check(a,b);
        }
        union1(a,b);
    }
    if(ch==1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
