#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans1,ans2;
long long int pow(long long int a,long long int b)
{
    long long int ans=1;
    while(b!=0)
    {
        ans=ans*a;
        b--;
    }
    return ans;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans1=pow(2,n-1);
        ans2=(n-1)*pow(2,n-2)+pow(2,n-1);
        printf("%lld %lld\n",ans1,ans2);
    }
}
