#include<stdio.h>
int main()
{
	long long int t,i,j,s,n,k,d;
	scanf("%d",&t);
	long long int a[t],b[t];
	for(i=0;i<t;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<t;i++)
	{
		j=a[i];
		k=1;
		while(k==1)
		{
			n=j;
			s=0;
			while(n!=0)
			{
				d=n%10;
				s=s+d;
				n=n/10;
			}
			if(j%s==0)
			{
				printf("%lld",j);
				printf("\n");
				k=0;
			}
			else
				j++;
		}
	}
	return 0;
}
