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
	double a,B,c,d,X,x,Y,y,Z,z,v,s1,s2,s3,s4,a1,a2,a3,a4,r;
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
		s1=(b[i][0]+b[i][1]+b[i][3])/2;
		a1=sqrt(s1*(s1-b[i][0])*(s1-b[i][1])*(s1-b[i][3]));
		s2=(b[i][3]+b[i][5]+b[i][4])/2;
		a2=sqrt(s2*(s2-b[i][3])*(s2-b[i][5])*(s2-b[i][4]));
		s3=(b[i][0]+b[i][4]+b[i][2])/2;
		a3=sqrt(s3*(s3-b[i][0])*(s3-b[i][4])*(s3-b[i][2]));
		s4=(b[i][1]+b[i][5]+b[i][2])/2;
		a4=sqrt(s4*(s4-b[i][1])*(s4-b[i][5])*(s4-b[i][2]));
		r=v*3/(a1+a2+a3+a4);
		printf("%.4lf\n",r);
	}
	return 0;
}
