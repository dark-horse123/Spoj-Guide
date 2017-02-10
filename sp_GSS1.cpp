#include<bits/stdc++.h>
using namespace std;
#define INT_MIN -100000000
#define lli long long int
int a[50002];
struct node
{
    int pre,suf,sum,best_sum;
    void merge(node left,node right)
    {
        sum=left.sum+right.sum;
        suf=max(right.suf,left.suf+right.sum);
        pre=max(left.pre,left.sum+right.pre);
        best_sum=max(left.suf+right.pre,max(left.best_sum,right.best_sum));
    }
    node()
    {
        best_sum=pre=suf=sum=INT_MIN;
    }
}tree[200000];
void build(int i,int left,int right)
{
    if(left==right)
    {
        tree[i].pre=a[left];
        tree[i].suf=a[left];
        tree[i].sum=a[left];
        tree[i].best_sum=a[left];
    }
    else
    {
        int mid=(left+right)/2;
        build(2*i,left,mid);
        build(2*i+1,mid+1,right);
        tree[i].merge(tree[2*i],tree[2*i+1]);
    }
}
node query(int i,int left,int right,int l,int r)
{
    if(left>=l&&right<=r)
        return tree[i];
    int mid=(left+right)/2;
    node l1=node(),r1=node();
    if(l<=mid)
        l1=query(2*i,left,mid,l,r);
    if(r>mid)
        r1=query(2*i+1,mid+1,right,l,r);
    node temp=node();
    if(l1.best_sum==INT_MIN)
        return r1;
    if(r1.best_sum==INT_MIN)
        return l1;
    temp.merge(l1,r1);
    return temp;
}
int main()
{
    int i,j,x,y,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",query(1,1,n,x,y).best_sum);
    }
}
