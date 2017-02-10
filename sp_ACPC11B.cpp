#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n1,n2,a[1005],b[1005],i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        for(i=0;i<n1;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&n2);
        for(i=0;i<n2;i++)
        {
            scanf("%d",&b[i]);
        }
        int min=1000000;
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                if(min>fabs(b[j]-a[i]))
                    min=fabs(b[j]-a[i]);
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
