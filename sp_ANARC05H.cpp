#include<bits/stdc++.h>
using namespace std;
char a[32];int l,sum;
int sub(int s,int p)
{
    int i,s1=0,ans=0;
    if(p==l)
        return 1;
    for(i=p;i<l;i++)
    {
        s1+=a[i]-'0';
        if(s1>=s)
        {
            ans+=sub(s1,i+1);
        }
    }
    return ans;
}
int main()
{
    int t,cnt=1;
    while(scanf("%s",a)==1&&isdigit(a[0]))
    {
        l=strlen(a);
        printf("%d. %d\n",cnt++,sub(0,0));
    }
    return 0;
}
