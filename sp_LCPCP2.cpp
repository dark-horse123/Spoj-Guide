#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,a,b,c,m;
    scanf("%lld",&t);long long int i=1;
    while(t--)
    {
        m=1;
        scanf("%lld%lld%lld",&a,&b,&c);
        while(b!=0)
        {
            if(b%2==1)
            {
                m=m*a;
                m=m%c;
            }
            a=a*a;
            a=a%c;
            b=b/2;
        }
        printf("%lld. %lld\n",i,m);
        i++;
    }
    return 0;
}
