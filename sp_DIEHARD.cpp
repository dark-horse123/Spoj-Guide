#include<bits/stdc++.h>
using namespace std;
int check(int h,int a,int prev)
{
    if(h<=0||a<=0)
        return 0;
    int air=0,fire=0,water=0;
    if(prev==1)
    {
        if(h>=20)
            fire=1+check(h-20,a+5,2);
        else
            fire=0;
        if(h>=5&&a>=10)
            water=1+check(h-5,a-10,3);
        else water=0;
        return max(fire,water);
    }
    else
    {
        return 1+check(h+3,h+2,1);
    }
}
int main()
{
    int t,h,a;
    cin>>t;
    while(t--)
    {
        cin>>h>>a;
        int fire=0,water=0;
        if(h>=20)
            fire=1+check(h-20,a+5,2);
        else fire=0;
        if(h>=5&&a>=10)
            water=1+check(h-5,a-10,3);
        else water=0;
        cout<<max(1+check(h+3,a+2,1),max(fire,water))<<endl;
    }
}
