#include<stdio.h>
#include<math.h>
int main()
{
	long int i=0,t=0,b=0,p=0;
	scanf("%ld",&t);
	long int a[t][2];long int s=0,n=0,k=0,h=0,j=0;
	for(i=0;i<t;i++)
	{
		scanf("%ld",&a[i][0]);
		scanf("%ld",&a[i][1]);
	}
	for(i=0;i<t;i++)
	{
		b=0;
		for(j=a[i][0];j<=a[i][1];j++)
		{
			p=0;s=0;
			for(k=1;k<=sqrt(a[i][j]);k++)
			{
				if(j%k==0)
				{
					s=s+k+j/k;
				}	
			}
			h=sqrt(j);
			if(h*h==j)
			s=s-sqrt(j);
			for(n=2;n<=sqrt(s);n++)
			{
				if(s%n==0)
				{
					p=1;
					break;
				}
			}
			if(p==0)
			b++;
		}
		printf("%ld\n",b);
	}
	return 0;
}
