#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,p=0;
    scanf("%lld",&n);
    long long int a[n][2];
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }long long int k=1;p=max(a[0][0],a[0][1]);
    for(i=1;i<n;i++)
    {
        if(k%2!=0)
        {
            p=p+min(a[i][0],a[i][1]);
            p=p+fabs(max(a[i][0],a[i][1])-min(a[i-1][0],a[i-1][1]));
        }
        else if(k%2==0)
        {
            p=p+max(a[i][0],a[i][1]);
            p=p+fabs(min(a[i][0],a[i][1])-max(a[i-1][0],a[i-1][1]));
        }
        k++;
    }
    printf("%lld\n",p);
    return 0;
}
