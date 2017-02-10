#include<stdio.h>
#include<math.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	double b[t][6];
	for(i=0;i<t;i++)
	{
			scanf("%lf%lf%lf%lf%lf%lf",&b[i][0],&b[i][1],&b[i][2],&b[i][3],&b[i][4],&b[i][5]);
	}
	double a,B,c,d,X,x,Y,y,Z,z,v;
	for(i=0;i<t;i++)
	{
		X=(b[i][4]-b[i][0]+b[i][2])*(b[i][0]+b[i][2]+b[i][4]);
		x=(b[i][0]-b[i][2]+b[i][4])*(b[i][2]-b[i][4]+b[i][0]);
		Y=(b[i][5]-b[i][3]+b[i][4])*(b[i][3]+b[i][4]+b[i][5]);
		y=(b[i][3]-b[i][4]+b[i][5])*(b[i][4]-b[i][5]+b[i][3]);
		Z=(b[i][2]-b[i][1]+b[i][5])*(b[i][1]+b[i][5]+b[i][2]);
		z=(b[i][1]-b[i][5]+b[i][2])*(b[i][5]-b[i][2]+b[i][1]);
		a=sqrt(x*Y*Z);
		B=sqrt(y*Z*X);
		c=sqrt(z*X*Y);
		d=sqrt(x*y*z);
		v=sqrt((-a+B+c+d)*(a-B+c+d)*(a+B-c+d)*(a+B+c-d))/(192*b[i][5]*b[i][2]*b[i][4]);
		printf("%.4lf\n",v);
	}
	return 0;
}
