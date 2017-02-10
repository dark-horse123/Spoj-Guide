#include<bits/stdc++.h>
using namespace std;
int size[100005],arr[100005];
int root(int a)
{
    while(arr[a]!=a)
    {
        a=arr[a];
    }
    return a;
}
void w_union(int a,int b)
{
    int root_a=root(a);int root_b=root(b);
    if(size[a]>size[b])
    {
        arr[root_b]=arr[root_a];
        size[root_a]+=size[root_b];
    }
    else
    {
        arr[root_a]=arr[root_b];
        size[root_b]+=size[root_a];
    }
}
int main()
{
    int i,t;
    scanf("%d",&t);
    while(t--)
    {
        int p,r;
        scanf("%d%d",&p,&r);
        int a,b;
        memset(size,1,sizeof(size));
        for(i=1;i<=100005;i++)
            arr[i]=i;
        int cnt=0;
        for(i=0;i<r;i++)
        {
            scanf("%d%d",&a,&b);
            int ch_a=a,ch_b=b;
            while(arr[ch_a]!=ch_a)
                ch_a=arr[ch_a];
            while(arr[ch_b]!=ch_b)
                ch_b=arr[ch_b];
            if(ch_a==ch_b)
                cnt++;
            else
            {
                w_union(a,b);
            }
        }
        printf("%d\n",cnt);
    }
}
