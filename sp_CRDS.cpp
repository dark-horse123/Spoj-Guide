#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        k=((3*n*(n+1))/2-n)%1000007;
        printf("%lld\n",k);
    }
    return 0;
}
