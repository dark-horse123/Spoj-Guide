#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a1,b1,c1,l1,l2,l3,i;
    scanf("%d",&t);
    while(t--)
    {
        char a[25],b[2],c[25],d[2],e[25];
        scanf("%s%s%s%s%s",a,b,c,d,e);
        int k=0;
        l1=strlen(a);
        l2=strlen(c);
        l3=strlen(e);int ch=0;
        for(i=0;i<l1;i++)
        {
            if(a[i]>=97&&a[i]<=122)
            {
                ch=1;break;
            }
        }
        if(ch==0)
        {
            for(i=0;i<l2;i++)
            {
                if(c[i]>=97&&c[i]<=122)
                {
                    ch=2;break;
                }
            }
        }
        if(ch==0)
        {
            ch=3;
        }
        switch(ch)
        {
            case 1:
            {
                b1=std::atoi(c);
                c1=std::atoi(e);
                a1=c1-b1;
                printf("%d + %d = %d\n",a1,b1,c1);
                break;
            }
            case 2:
            {
                a1=std::atoi(a);
                c1=std::atoi(e);
                b1=c1-a1;
                printf("%d + %d = %d\n",a1,b1,c1);
                break;
            }
            case 3:
            {
                a1=std::atoi(a);
                b1=std::atoi(c);
                c1=a1+b1;
                printf("%d + %d = %d\n",a1,b1,c1);
                break;
            }
        }
    }
    return 0;
}
