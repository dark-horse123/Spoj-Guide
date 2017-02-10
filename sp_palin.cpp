#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int t,i,j,l,h,k=1,len;
    cin>>t;
    while(t--)
    {
        char a[1000000],b[1000000]={'0'},a1;
        cin>>a;
        len=strlen(a);int t1=0;
        for(i=0;i<len;i++)
        {
            if(a[i]!='9')
            {
                t1=1;break;
            }
        }int t2=1;
        if(t1==0)
        { t2=0;
            for(i=0;i<=len;i++)
            {
                if(i==0||i==len)
                    cout<<'1';
                else
                    cout<<'0';
            }
            cout<<endl;
        }t1=0;j=len-1;
        for(i=0;i<len/2;i++)
        {
            if(a[i]!=a[j-i])
            {
                t1=1;break;
            }
        }
        if(t1==0&&t2==1)
        {
            int z;if(len%2==0)z=len/2-1;else z=len/2;
            for(i=z;i>=0;i--)
            {
                if(a[i]!='9')
                {
                    a[i]=a[i]+1;b[i]='1';
                    a[j-i]=a[i];b[j-i]='1';
                    break;
                }
            }
        }
        else if(t1!=0&&t2==1)
        {
            if(len%2==0)
            {
                h=len/2;
                l=len/2-1;
            }
            else
            {
                h=len/2+1;a1=a[len/2];
                l=len/2-1;
            }k=1;
            while(k)
            {
                if(a[l]>a[h])
                {
                    a[h]=a[l];b[h]='1';b[l]='1';if(len%2!=0)a[len/2]=a1;
                }
                else if(a[l]<a[h])
                {
                    if(len%2!=0)
                    {
                        long long int l1=len/2,h1=len/2;int temp=0;
                        while(l1>l&&h1<h)
                        {
                            if(b[l1]=='1'&&l1==l+1)
                            {
                                for(i=l+1;i<h;i++)
                                    a[i]='0';
                                a[l]=a[l]+1;a[h]=a[l];b[h]='1';b[l]='1';break;
                            }
                            if(a[l1]!='9')
                            {
                                if(b[l1]=='1')
                                    {a[h]=a[l];b[h]='1';b[l]='1';break;}
                                a[h1]=(a[h1])+1;
                                a[l1]=a[h1];
                                temp=1;
                                a[h]=a[l];b[h]='1';b[l]='1';
                                break;
                            }
                            else if(a[l1]=='9'&&a[h1]=='9')
                            {
                                while(a[l1]=='9'&&a[h1]=='9')
                                {
                                    a[l1]='0';a[h1]='0';b[l1]='1';b[h1]='1';l1--;h1++;
                                }
                                a[l]=a[l]+1;a[h]=a[l];
                                break;
                            }
                            b[l1]='1';b[h1]='1';l1--;h1++;
                        }
                    }
                    else
                    {
                        long long int l1=len/2-1,h1=len/2;int temp=0;
                        while(l1>l&&h1<h)
                        {
                            if(b[l1]=='1'&&l1==l+1)
                            {
                                for(i=l+1;i<h;i++)
                                    a[i]='0';
                                a[l]=a[l]+1;a[h]=a[l];b[h]='1';b[l]='1';break;
                            }
                            if(a[l1]!='9')
                            {
                                if(b[l1]=='1')
                                    {a[h]=a[l];b[h]='1';b[l]='1';break;}
                                a[l1]=(a[l1])+1;b[l1]='1';
                                a[h1]=a[l1];b[h1]='1';
                                temp=1;
                                a[h]=a[l];b[h]='1';b[l]='1';
                                break;
                            }
                            else if(a[l1]=='9'&&a[h1]=='9')
                            {
                                while(a[l1]=='9'&&a[h1]=='9')
                                {
                                    a[l1]='0';a[h1]='0';b[l1]='1';b[h1]='1';l1--;h1++;
                                }
                                a[l]=a[l]+1;a[h]=a[l];
                                break;
                            }
                            b[l1]='1';b[h1]='1';l1--;h1++;
                        }
                    }
                }l--;h++;
                int temp1=0;
                for(i=0;i<len;i++)
                {
                    if(a[i]!=a[len-i-1])
                    {
                        temp1=1;
                        break;
                    }
                }
                if(temp1==0)
                {
                    k=0;
                }
            }
        }if(t2==1)
        {for(i=0;i<len;i++)
                cout<<a[i];
            cout<<endl;}
    }
    return 0;
}
