#include<bits/stdc++.h>
using namespace std;
struct stop
{
     int dist;
     int fuel;
     bool operator <(const stop& p) const
     {
       return dist > p.dist;
     }
};
stop a[10004];
int heap[10004],cnt;
int dist_max()
{
  if(cnt==0) return -1;
  int max=heap[1];
  int value = heap[cnt--];
  int i=1,child;
  while(i*2<=cnt){
  child = (i*2);
    if((child+1) <= cnt && heap[child+1] > heap[child]) child++;
    if(heap[child]>value) heap[i]=heap[child];
    else break;
    i=(child);

  }
  heap[i]=value;
  return max;
}
void push(int x)
{
  cnt++;
  int i=cnt;
  while(i!=1){
    if(heap[i/2]<x)heap[i]=heap[i/2];
    else break;
    i/=2;
  }
  heap[i]=x;
}
int check(const void *_x,const void *_y){
    stop *x=(stop *)_x,*y=(stop *)_y;
       return y->dist-x->dist;
}
int main()
{
int n,i,j,k,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=n-1;i>=0;i--){
      scanf("%d %d",&a[i].dist,&a[i].fuel);
   }
   int fuel,dist,flag,flag2,l,m;
    a[n].dist=0;
    a[n].fuel=0;
    sort(a,a+(n+1));
    scanf("%d %d",&dist,&fuel);
    i=0;k=0;cnt=0;
   while(i<=n)
    {
        while(i<=n && (dist - a[i].dist <= fuel))
        {
            fuel -= (dist-a[i].dist);
            dist = a[i].dist;
            push(a[i].fuel);
            i++;
        }
        if(i<=n)
        {
            int temp = dist_max();
            if(temp==-1){
            k=-1;
            break;
        }
            fuel+= temp;
            k++;
        }
    }
    printf("%d\n",k);
  }
  return 0;
}
