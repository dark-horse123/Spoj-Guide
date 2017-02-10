#include<bits/stdc++.h>
using namespace std;
char* reverse1(char st[])
{
    for(int i=0;i<strlen(st)/2;i++)
    {
        char temp;
        temp=st[i];
        st[i]=st[strlen(st)-1-i];
        st[strlen(st)-1-i]=temp;
    }
    return st;
}
bool check(char* n)
{

}
void sum(char* s,char* s1)
{
    s=reverse1(s);
    //cout<<s<<endl;
    s1=reverse1(s1);
    //cout<<s1<<endl;
    int l1=strlen(s),l2=strlen(s1);
    cout<<l1<<" "<<l2<<endl;
    if(l1>l2)
        for(int i=l2;i<l1;i++)
            s1[i]='0';
    else
        for(int i=l1;i<l2;i++)
            s[i]='0';
    cout<<s<<" "<<s1<<endl;
    int carry=0,i=0,cursum=0;char sum[1002];
    while(i<strlen(s))
    {
        cursum=carry+(s[i]-'0')+(s1[i]-'0');
        sum[i]=cursum%10+'0';
        carry=cursum/10;
        i++;
    }
    while(carry!=0)
    {
        sum[i]=carry%10+'0';
        carry=carry/10;
        i++;
    }
    strcpy(s,sum);
    s=reverse1(s);
    //cout<<s<<endl;
}
void multiply(char* n,char* s)
{
    int carry=0;

}
int main()
{
    char s[1000],n[1000],s1[1000];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        strcpy(s,n);
        strcpy(s1,"1");
        sum(s,s1);
        /*while(1)
        {
            if(!check(n))
            {
                sum(s,'1');
                multiply(n,s);
            }
        }*/
    }
}
