#include<bits/stdc++.h>
#include<cstdio>
#include<stack>
using namespace std;

int n;
int arrm[1015][1015];
int arrs[1015][1015];
int T[1015][1015];
int m[1100000];
int s[1100000];

int main()
{
	int t;
	memset(T,-1,sizeof(T));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
       		int arrm[n+1][n+1], arrs[n+1][n+1];
		arrm[0][0] = 0; arrs[0][0]  = 0;T[0][0] = t;
		int p = 0, q=0;
		m[p] = 0, s[p++] = 0;
		while(q<p) {
			int j = m[q],i=  s[q++];
			for(int k = 0; k < 10; k++)
			{
				int im = (j*10+k)%n;
				if(i+k > n) break;
				if(T[i+k][im] != t) {
					arrm[i+k][im] = j, arrs[i+k][im] = i;
					T[i+k][im] = t;
					m[p] = im, s[p++] = i+k;
				}
				if(i+k == n && im == 0) goto here;
			}
		}

		here:
		stack<int> st;
		int is = n, im = 0;
		while(is != 0 || im != 0)
		{
			st.push(is-arrs[is][im]);
			int iim;
			iim = arrm[is][im],  is = arrs[is][im] ;
			im=iim;
		}
		while(!st.empty()) {printf("%d",st.top()); st.pop();}
                printf("\n");
	}
}

