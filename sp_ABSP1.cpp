#include<bits/stdc++.h>
using namespace std;
long long a[10004];
int main()
{
    long long int t,n,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }long long int j=1,k=0,s;
        s=-a[0]*(n-1);
        for(i=1;i<n;i++)
        {
            s=s+a[i]*(i)-a[i]*(n-i-1);
        }
        printf("%lld\n",s);
    }
    return 0;
}
