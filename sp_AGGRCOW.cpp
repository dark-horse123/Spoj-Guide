#include<bits/stdc++.h>
using namespace std;
long int a[100005];
int main()
{
    long int i1,c1,k1,i,t1,t,n1,n,c,k;
    scanf("%ld",&t);
    while(t--)
    {
        k=-100000;
        scanf("%ld%ld",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
        sort(a,a+n);
        long int mid;
        long int l=a[0],h=a[n-1];
        while(l<h)
        {
           mid=(l+h)/2;
           i1=0;c1=1;k1=1000000000;
            for(i=0;i<n;i++)
            {
                t1=a[i]-a[i1];
                if((t1)>=mid)
                {
                    i1=i;
                    c1++;
                    if(k1>(t1))
                        k1=t1;

                }
                if(c1==c)
                {
                    break;
                }
            }
            if(c1==c)
            {
                l=mid+1;
                if(k<k1)
                    k=k1;
            }
            else
            {
                h=mid;
            }
        }
        if(c<=1)
            printf("0\n");
        else
            printf("%ld\n",k);
    }
    return 0;
}
