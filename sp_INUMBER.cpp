#include<bits/stdc++.h>
using namespace std;
struct node{
int sum,mod;
};
typedef struct node node;
queue<node> q;
stack<int> ans;
int sum1[1005][1005],mod1[1005][1005],check[1005][1005];
void bfs(int n)
{
    int i=0,j,k=0;
    node temp1;
    node temp;check[0][0]=1;sum1[0][0]=0;mod1[0][0]=0;
    temp1=q.front();
    while(temp1.sum<n||temp1.mod>0)
    {
        for(j=0;j<=9;j++)
        {
            if(temp1.sum+j>n) break;
            int t1=(temp1.mod*10+j)%n;
            if(check[temp1.sum+j][t1]!=1)
            {
                sum1[temp1.sum+j][t1]=temp1.sum;
                mod1[temp1.sum+j][t1]=temp1.mod;
                check[temp1.sum+j][t1]=1;
                temp.sum=temp1.sum+j;
                temp.mod=t1;
                q.push(temp);
            }
        }
        q.pop();
        temp1=q.front();
    }
    int a=n,b=0,s1,m1,a1,b1;
    while(a!=0||b!=0)
    {
        s1=a-sum1[a][b];
        ans.push(s1);
        a1=sum1[a][b];m1=mod1[a][b];b=m1;a=a1;
    }
    int l=ans.size();
    for(i=0;i<l;i++)
    {
        printf("%d",ans.top());
        ans.pop();
    }
    printf("\n");
}
void clear1()
{
    queue<node> empty1;
    swap(q,empty1);
    stack<int> empty2;
    swap(ans,empty2);
}
int main()
{
    long long int t,n,i;
    scanf("%lld",&t);
    while(t--)
    {
        clear1();memset(check,0,sizeof(check));
        scanf("%lld",&n);
        node temp;
        for(i=1;i<=9;i++)
        {
            temp.sum=i;
            temp.mod=i%n;
            sum1[i][i%n]=0;
            mod1[i][i%n]=0;
            check[i][i%n]=1;
            q.push(temp);
        }
        bfs(n);
    }
}
