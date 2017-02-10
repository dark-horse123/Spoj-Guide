#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
int pos;};
typedef struct node node;

int main()
{
    int t1,n,j,i;
    node t;
    scanf("%d",&t1);
    queue<node> q;
    while(t1--)
    {
        int ans[20005];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            t.val=-1;
            if(i==1)
                t.val=1;
            t.pos=i;
            q.push(t);
        }
        q.push(q.front());
        q.pop();
        while(!q.empty())
        {
            t=q.front();
            if(q.front().val==n)
            {
                ans[q.front().pos]=n;
                q.pop();break;
            }
            q.pop();
            ans[t.pos]=t.val;
            for(i=1;i<=t.val+1;i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.front().val=i-1;
        }
        if(n==1)
            printf("1");
        else
        for(i=0;i<n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
}
