#include<bits/stdc++.h>
using namespace std;
int n1,n2,a[10004],b[10004];
int main()
{
    while(1)
    {
        int i;
        scanf("%d",&n1);
        if(n1==0)
            break;
        for(i=0;i<n1;i++)
            scanf("%d",&a[i]);
        scanf("%d",&n2);
        for(i=0;i<n2;i++)
            scanf("%d",&b[i]);
        int low=0,i1,s=0,check=0,s1=0,ans=0;
        i=0;
        while(i<n2)
        {
            check=0;s1=s1+b[i];
            i1=low;
            while(i1<n1)
            {
                s=s+a[i1];
                if(a[i1]>b[i])
                {
                    i++;s1=s1+b[i];check=1;
                    while(b[i]<a[i1]&&i<n2)
                    {
                        i++;
                        s1=s1+b[i];
                    }
                    if(b[i]==a[i1])
                    {
                        //cout<<s<<" "<<s1<<endl;
                        ans=ans+max(s,s1);
                        i++;
                        low=i1+1;
                        s1=0;s=0;
                        break;
                    }
                    else if(b[i]>a[i1])
                    {
                       // s1=s1+b[i];
                        low=i1+1;
                    }
                    if(low>=n1)
                    {
                        while(i<n2)
                        {
                            s1=s1+b[i];i++;
                        }
                        ans=ans+max(s,s1);
                    }
                }
                else if(a[i1]==b[i])
                {
                    //cout<<s<<" "<<s1<<" ";
                    ans=ans+max(s,s1);//cout<<ans<<endl;
                    i++;check=1;
                    low=i1+1;
                    s1=0;s=0;
                    if(low>=n1)
                    {
                        while(i<n2)
                        {
                            s1=s1+b[i];i++;
                        }
                        ans=ans+max(s,s1);
                    }
                    break;
                }
                i1++;
            }
            if(!check)
                i++;
            if(i>=n2)
            {
                while(low<n1)
                {
                    ans=ans+a[low];low++;
                }
            }
        }
        if(s1!=0||s!=0)
            ans=ans+max(s,s1);
        cout<<ans<<endl;
    }
}
