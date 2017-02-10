#include<bits/stdc++.h>
using namespace std;
int t,n,m,st_x,st_y,end_x,end_y;char s[1002][1002];
int dist[1002][1002],dir[1002][1002];
struct node{
int x,y,d;};
typedef struct node node;
int dir1[]={-1,-1,-1,0,0,1,1,1};
int dir2[]={-1,0,1,-1,1,-1,0,1};
int bfs()
{
    int i;
    queue<node> q;
    node temp;
    temp.x=st_x;
    temp.y=st_y;
    temp.d=0;
    q.push(temp);
    while(!q.empty())
    {
        node temp1;
        temp1=q.front();q.pop();
        if(temp1.x==end_x&&temp1.y==end_y)
            return temp1.d;
        if(s[temp1.x][temp1.y]=='X'||dist[temp1.x][temp1.y]<temp1.d)
            continue;
        for(i=0;i<8;i++)
        {
            if(dir[temp.x][temp.y]&(1<<i)==1)
                continue;
            dir[temp.x][temp.y]=dir[temp.x][temp.y]|(1<<i);
            int j=1,tx,ty;
            while(1)
            {
                tx=temp1.x+j*dir1[i];
                ty=temp1.y+j*dir2[i];
                if(tx>=0&&ty>=0&&tx<n&&ty<m&&s[tx][ty]!='X')
                {
                    if(dist[tx][ty]>temp1.d+1)
                    {
                        node temp2;
                        temp2.x=tx;temp2.y=ty;temp2.d=temp1.d+1;
                        dist[tx][ty]=temp1.d+1;
                        q.push(temp2);
                    }
                    j++;
                }
                else
                    break;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&t);int i,j;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(dir,0,sizeof(dir));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                dist[i][j]=1000000;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }int k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {

                if(s[i][j]=='S')
                {st_x=i;st_y=j;k++;}
                else if(s[i][j]=='F')
                {end_x=i;end_y=j;k++;}
                if(k==2)
                    break;
            }
        }
    printf("%d\n",bfs());
    }
}
