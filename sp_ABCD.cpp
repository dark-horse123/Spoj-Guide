#include<bits/stdc++.h>
using namespace std;
char arr[100005],arr1[100005];
int main()
{
    int i,n,j;
    scanf("%d",&n);
    scanf("%s",arr);
    for(i=0;i<2*n;i+=2)
    {
        int a1[4];
        memset(a1,0,sizeof(a1));
        a1[arr[i]-65]=1;
        a1[arr[i+1]-65]=1;int k=i;
        for(j=0;j<4;j++)
        {
            if(a1[j]==0)
            {
                arr1[k]=65+j;
                k++;
            }
        }
        if(arr1[i]==arr1[i-1])
            swap(arr1[i],arr1[i+1]);
    }
    printf("%s",arr1);
    return 0;
}
