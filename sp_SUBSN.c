#include<stdio.h>
#include<stdlib.h>
char s[100004],t[204];
int l,l1;
int main()
{
    int test,k,i,j,check=0,q;
    char c;
    scanf("%d",&test);
    fgets(s,100004,stdin);
    for(k=1;k<=test;k++)
    {
        fgets(s,100004,stdin);
        l=strlen(s);
        scanf("%d",&q);
        printf("Case %d:\n",k);
        fgets(t,204,stdin);
        while(q--)
        {
            fgets(t,204,stdin);
            l1=strlen(t);
            if(strcmp(s,t) == 0)
                printf("YES\n");
            else if(l<l1)
                printf("NO\n");
            else if(t[0] == "\n")
                printf("YES\n");
            else
            {
                int low=0;
                for(i=0;i<l1;i++)
                {
                    check=0;
                    for(j=low;j<l;j++)
                    {
                        if(s[j]==t[i])
                        {
                            check=1;
                            low=j+1;
                            break;
                        }
                    }
                    if(check==0)
                        break;
                }
                if(check==0)
                    printf("NO\n");
                else printf("YES\n");
            }
        }
    }
}
