#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d1,d2,r1;
    scanf("%d%d%d",&a,&b,&c);
    while(a!=0||b!=0||c!=0)
    {
        d1=b-a;d2=c-b;
        if(a==b==c)
        {
            r1=c/b;
            printf("GP %d\n",c*r1);
        }
        else if(d1==d2)
        {
            printf("AP %d\n",c+d2);
        }
        else
        {
            r1=c/b;
            printf("GP %d\n",c*r1);
        }
        scanf("%d%d%d",&a,&b,&c);
    }
    return 0;
}
