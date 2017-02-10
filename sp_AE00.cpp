#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int k=0,k1,n1,s;
    for(i=1;i<=sqrt(n);i++)
    {
        s=i;k1=i;
        while(1)
        {
            n1=s*k1;
            k1++;
            if(n1<=n)
            {
                k++;
            }
            else
                break;
        }
    }
    printf("%d\n",k);
    return 0;
}
