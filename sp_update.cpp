#include<bits/stdc++.h>
using namespace std;
long long int t,n,u,l,r;
long long int val,q,ind,i,a[10005],s[10005];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        scanf("%lld%lld",&n,&u);
        for(i=0;i<u;i++)
        {
            scanf("%lld%lld%lld",&l,&r,&val);
            s[l]+=val;s[r+1]-=val;
        }a[0]=s[0];
        for(i=1;i<n;i++)
        {
            a[i]=a[i-1]+s[i];
        }
        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&ind);
            printf("%lld\n",a[ind]);
        }
    }
    return 0;
}

