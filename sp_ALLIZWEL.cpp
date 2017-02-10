#include<bits/stdc++.h>
using namespace std;
vector <string> adj;
char a[]="ALLIZZWELL";
int v[105][105],r,c;
bool dfs(int i,int j,int l)
{
	if(l==10)
		return 1;
	v[i][j]=1;int r1,c1;
	for(int i1=-1;i1<=1;i1++)
	{
		for(int j1=-1;j1<=1;j1++)
		{
			r1=i+i1;c1=j+j1;
			if((i1==0&&j1==0)||r1<0||c1<0||r1>=r||c1>=c||adj[r1][c1]!=a[l]||v[r1][c1]==1)
				continue;
			if(dfs(r1,c1,l+1))
            {
                v[i][j]=0;
				return 1;
            }
		}
	}
	v[i][j]=0;
	return 0;
}
int main()
{
	int t,i,j;bool k=0;
	char s[105];
	scanf("%d",&t);
	while(t--)
	{
		k=0;adj.clear();
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
		{
			scanf("%s",s);
			adj.push_back(s);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(adj[i][j]=='A'&&dfs(i,j,1))
				{
					k=1;
					break;
				}
			}
		}
		if(k==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
