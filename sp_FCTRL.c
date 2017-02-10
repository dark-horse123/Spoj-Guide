#include<stdio.h>
#include<math.h>
int main()
{
	long int i,t,gi=1,s5=0,n;
	scanf("%d",&t);
	long int a[t],b[t];
	for(i=0;i<t;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<t;i++)
	{
		s5=0;
		n=1;gi=1;
		while(gi!=0)
		{
			gi=a[i]/(pow(5,n));
			s5=s5+gi;
			n++;
		}
		b[i]=s5;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n",b[i]);
	}
	return 0;
}
