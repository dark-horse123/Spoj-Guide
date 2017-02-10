#include<bits/stdc++.h>
using namespace std;
int c[10005][2],d[10005][2],e[1000000][2],f[1000000][2];
int main()
{
    int n;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    memset(f,0,sizeof(f));
    scanf("%d",&n);
    long int a[n],i,j,k;//c[(n*(n+1))/2],d[(n*(n+1))/2];
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    sort(a,a+n);
    i=0;
    for(j=0;j<n;j++)
    {
        for(k=j;k<n;k++)
        {
            c[i][0]=a[j]*a[k];
            if(a[j]==a[k])
                c[i][1]=1;
            d[i][0]=a[j]+a[k];
            if(a[j]==a[k])
                d[i][1]=1;
            i++;
        }
    }
    k=i;int j1=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            continue;
        for(j=0;j<k;j++)
        {
            e[j1][0]=a[i]*d[j][0];
            j1++;
        }
    }int j2=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            f[j2][0]=a[i]+c[j];
            j2++;
        }
    }sort(f,f+j2);
    for(i=0;i<j1;i++)
    {
        bsearch()
    }
}
