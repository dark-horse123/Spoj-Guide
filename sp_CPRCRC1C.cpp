#include<bits/stdc++.h>
using namespace std;
long long int sum(long long int n)
{
    if(n/10==0)
        return n*(n+1)/2;
    int i=0;
    long long int n1=n;
    while(n1/10!=0)
    {
        i++;
        n1=n1/10;
    }
    int p=pow(10,i);
    return (45*n1*p*i)/10+n1*(n1-1)*p/2+n1*(n%p+1)+sum(n%p);
}
int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    while(a!=-1&&b!=-1)
    {
        printf("%lld\n",sum(b)-sum(a-1));
        scanf("%lld%lld",&a,&b);
    }
}
