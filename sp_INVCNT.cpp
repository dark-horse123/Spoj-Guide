#include<bits/stdc++.h>
using namespace std;
//map<long long int,long long int> m1;
long long int p[200002],left1[200002],right1[200002];
long long int t,n;
long long int ans;
void mergearray(long long int l,long long int k,long long int h)
{
    long long int j;
    for(j=0;j<k-l+1;j++)
        left1[j]=p[l+j];
    for(j=0;j<h-k;j++)
        right1[j]=p[k+j+1];
    long long int i1=0,i2=0,i=l;
    while(i1<k-l+1&&i2<h-k)
    {
        if(left1[i1]<right1[i2])
        {
            p[i]=left1[i1];
            i1++;
        }
        else if(left1[i1]>right1[i2])
        {
            p[i]=right1[i2];
            i2++;
            ans=ans+k-(i1+l)+1;
        }
        i++;
    }
    while(i1<k-l+1)
    {
        p[i]=left1[i1];
        i++;i1++;
    }
    while(i2<h-k)
    {
        p[i]=right1[i2];
        i++;i2++;
    }
}
void mergesort(long long int l,long long int h)
{
    long long int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergesort(l,mid);
        mergesort(mid+1,h);
        mergearray(l,mid,h);
    }
}
int main()
{
    long long int i,a;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            p[i]=a;
            // m1[a]=i;
        }
        ans=0;
        mergesort(0,n-1);
        printf("%lld\n",ans);
    }
}
