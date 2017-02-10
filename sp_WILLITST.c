#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,t;
	scanf("%lld",&n);
	t=log2(n);
	if(pow(2,t)==n)
	printf("TAK");
	else
	printf("NIE");
	return 0;
}
