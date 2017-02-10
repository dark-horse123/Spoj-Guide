#include<bits/stdc++.h>
using namespace std;
long long int f1=1,f2=3;
long long int f(long long int n)
{
    long long int ch;
    ch=n%3;
    switch(ch)
    {
    case 0:
        if(n%2==0)
            return f1-f2;
        else
            return f2-f1;
            break;
    case 1:
        if(n%2==0)
            return -f1;
        else
            return f1;
            break;
    case 2:
        if(n%2==0)
            return f2;
        else
            return -f2;
            break;
    }
}
int main()
{
    long long int n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("1\n");
        else if(n==2)
            printf("4\n");
        else
        {
            long long int ans=3+f(n-1);
            printf("%lld\n",ans);
        }
    }
}
