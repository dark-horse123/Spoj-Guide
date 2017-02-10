#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    int n,i,s=0,k,t;
    scanf("%ld",&n);
    while(n!=-1)
    {
        s=0;k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s=s+a[i];
        }
        if(s%n!=0)
        {
            printf("-1\n");
        }
        else
        {
            sort(a,a+n);
            i=n-1;t=s/n;
            while(a[i]>t)
            {
                k=k+a[i]-t;i--;
            }
            printf("%d\n",k);
        }
        scanf("%d",&n);
    }
    printf("\n");
    return 0;
}
