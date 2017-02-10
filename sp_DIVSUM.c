#include<stdio.h>
#include<math.h>
int main()
{
	 int i,s,k,t,p;
	scanf("%d",&t);
	int a[t];
	for(i=0;i<t;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<t;i++)
	{
			s=0;
			for(k=1;k<=sqrt(a[i]);k++)
			{
				if(a[i]%k==0)
				{
					s=s+k+a[i]/k;
				}	
			}
			p=sqrt(a[i]);
			if(p*p==a[i])
			s=s-sqrt(a[i])-a[i];
			else
			s=s-a[i];
				printf("%d\n",s);
	}
	return 0;		
}
