#include<bits/stdc++.h>
using namespace std;
long long int sum(long long int n)
{
	long long int i,d,r=0;
	while(n!=0)
	{
		d=n%10;
		r=r+d;
		n=n/10;
	}
	return r;
}
int main()
{
	long long int t,i,j,s,n,k,d;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		i=n;
		while(1)
		{
			if(i%sum(i)==0)
			{
				cout<<i<<endl;
				break;
			}
			i++;
		}
	}
	return 0;
}
