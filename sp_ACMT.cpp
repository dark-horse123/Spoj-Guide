#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,e,t1,t2,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&e);k=0;
        t1=min(n,e);
        t2=max(n,e);
        while(1)
        {
            if(t1<=1)
            {
                if(t1==1&&t2>=2)
                    k++;
                break;
            }
            else if(t1==t2)
            {
                t2--;
                t1-=2;
                k++;
            }
            else
            {
                t1--;
                t2-=2;
                k++;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
