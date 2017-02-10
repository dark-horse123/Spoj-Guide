#include<bits/stdc++.h>
using namespace std;
int a[100004];
int main()
{
    int t,i,n;
    scanf("%d",&t);
    while(t--)
    {
        long long int cnt=0,temp=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int maxsum=-100000,cursum=-100000;
        for(i=0;i<n;i++)
        {
            cursum=max(a[i],cursum+a[i]);
            maxsum=max(maxsum,cursum);
        }
        int ans=maxsum;long long int cnt1=0;
        if(ans==0)
        {
            for(i=0;i<n;i++)
            {
                if(a[i]==0)
                    cnt1++;
                else
                {
                    cnt=cnt+cnt1*(cnt1+1)/2;
                    cnt1=0;
                }
            }
            if(cnt1!=0)
                cnt=cnt+cnt1*(cnt1+1)/2;
        }
        else
        {
            maxsum=-100000,cursum=-100000;
            for(i=0;i<n;i++)
            {
                cursum=max(a[i],cursum+a[i]);
                if(cursum==0)
                    temp++;
                else if(cursum<0)
                    temp=0;
                if(cursum==ans)
                {
                    cnt=cnt+temp+1;
                    //temp=0;
                }
            }
        }
        cout<<ans<<" "<<cnt<<endl;
    }
}
