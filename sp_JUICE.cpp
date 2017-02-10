#include<bits/stdc++.h>
using namespace std;
#define lli long long in
#define INF 1000000000
int t,n,dp[1004];
vector< pair<int,int> > time1;
int main()
{
    int i,j,x,y;
    scanf("%d",&t);
    int k=1;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        time1.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            time1.push_back(make_pair(x,y));
        }
        sort(time1.begin(),time1.end());
        int cnt=0;
        for(i=0;i<n;i++)
        {
            cnt=0;
            for(j=i-1;j>=0;j--)
            {
                if(time1[j].first==time1[i].first)
                {
                    cnt++;
                    dp[j]=-INF;
                    continue;
                }
                if(time1[i].first<=time1[j+1].second&&time1[i].first>=time1[j+1].first)
                    cnt++;
                if(cnt>2)
                    dp[i]=max(dp[i],dp[j]+cnt);
                else dp[i]=max(dp[i],dp[j]);
            }
            if(time1[i].first<=time1[0].second&&time1[i].first>=time1[0].first)
                cnt++;
            if(cnt>2)
                dp[i]=max(dp[i],cnt);
        }
        printf("Case #%d: %d\n",k,dp[n-1]);
        k++;
    }
}

/*
2
10
1 10
2 11
3 12
4 13
13 14
14 15
13 19
20 22
21 23
22 24
10

1 1

1 2

3 3

1 4

3 5

3 6

3 7

8 8

3 9

3 10
*/
