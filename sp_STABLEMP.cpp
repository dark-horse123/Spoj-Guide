#include<bits/stdc++.h>
using namespace std;
int m[502][502],w[502][502];
int men[502][2];
int main()
{
    int n,i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=0;j<=n;j++)
                scanf("%d",&w[i][j]);
        for(i=1;i<=n;i++)
            for(j=0;j<=n;j++)
                scanf("%d",&m[i][j]);
        int m_engaged[502],w_engaged[502];
        for(i=0;i<=n;i++)
        {
            m_engaged[i]=0;
            w_engaged[i]=0;
        }
        deque<int> free;
        for(i=1;i<=n;i++)
            free.push_back(i);
        int num_eng=0;
        while(free.size()!=0)
        {
            int temp=free.front();
            for(i=1;i<=n;i++)
            {
                int check=0;
                if(w_engaged[m[temp][i]]!=0)
                {
                    int temp1=w_engaged[m[temp][i]];
                    j=1;
                    while(w[m[temp][i]][j]!=temp1)
                    {
                        if(w[m[temp][i]][j]==temp)
                        {
                            free.push_back(temp1);
                            free.pop_front();
                            m_engaged[temp]=m[temp][i];
                            w_engaged[m[temp][i]]=temp;
                            men[temp][0]=m[temp][i];
                            check=1;
                            break;
                        }
                        j++;
                    }
                }
                else if(w_engaged[m[temp][i]]==0)
                {
                    men[temp][0]=m[temp][i];
                    w_engaged[m[temp][i]]=temp;
                    m_engaged[temp]=m[temp][i];
                    free.pop_front();
                    break;
                }
                if(check)
                    break;
            }
        }
        for(i=1;i<=n;i++)
            cout<<i<<" "<<men[i][0]<<endl;
    }
    return 0;
}
