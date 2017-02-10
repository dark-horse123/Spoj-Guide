#include<bits/stdc++.h>
using namespace std;
double a=0,cx=0,cy=0,p;
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
    a=0;
    int n,i;cx=0;cy=0;
    scanf("%d",&n);
    int x[n+1],y[n+1];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    x[n]=x[0];
    y[n]=y[0];
    for(i=0;i<=n-1;i++)
    {
        p=(x[i]*y[i+1])-(x[i+1]*y[i]);
        cx+=p*(x[i]+x[i+1]);
        cy+=p*(y[i]+y[i+1]);
        a+=p;
    }
    a=a/2;
    cx=cx/(6*a);
    cy=cy/(6*a);
    if(fabs(cx)<0.005-(1e-9))
        cx = 0;
    if(fabs(cy)<0.005-(1e-9))
        cy = 0;
    printf("%.2f %.2f\n",cx+(1e-9)*(cx>=-1e-9?1:-1),cy+(1e-9)*(cy>=-1e-9?1:-1));
    }
}
