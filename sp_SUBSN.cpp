#include<bits/stdc++.h>
using namespace std;
string s,t;
int l,l1,mid=-1;
vector<int> adj[30];
int binarysearch(char c)
{
    int m=0,l=0,h=adj[c-'a'].size();
    if(h==0)
        return 0;
    while(l<=h)
    {
        m=l+(h-l)/2;
        if(adj[c-'a'][m]>mid)
            h=m;
        else if(adj[c-'a'][m]<=mid)
            l=m+1;
        if(l==h)
            break;
    }
    m=l+(h-l)/2;
    if(adj[c-'a'][m]<=mid)
        return 0;
    else
    {
        mid=adj[c-'a'][m];
        return 1;
    }
}
int main()
{
    int test,k,i,j,check=0,q;
    char c;
    scanf("%d",&test);
    getline(cin,s);
    for(k=1;k<=test;k++)
    {
        getline(cin,s);
        l=s.length();
        for(i=0;i<30;i++)
            adj[i].clear();
        for(i=0;i<l;i++)
            adj[s[i]-'a'].push_back(i);
        scanf("%d",&q);
        printf("Case %d:\n",k);
        getline(cin,t);
        while(q--)
        {
            getline(cin,t);
            l1=t.length();
            mid=-1;
            if(s==t)
                printf("YES\n");
            else if(t == "")
                printf("YES\n");
            else if(l<l1)
                printf("NO\n");
            else
            {
                for(i=0;i<l1;i++)
                {
                    check=binarysearch(t[i]);
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
