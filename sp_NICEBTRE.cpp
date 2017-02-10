#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > st;
char s[10005];int arr[20005],dist[20005];
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>s;int l=strlen(s);
        st.push_back(make_pair(0,0));
        memset(arr,0,sizeof(arr));
        memset(dist,0,sizeof(dist));
        i=1;
        if(s[0]=='l')
            cout<<0<<endl;
        else
        {
            while(!st.empty()&&i<=l-1)
            {
                if(arr[st.back().first]==2)
                {
                    if(st.size()>=2)
                        arr[st.back().second]++;
                    st.pop_back();
                    continue;
                }
                if(i<=l-1)
                {
                    dist[i]=dist[st.back().first]+1;
                    if(s[i]=='n')
                        st.push_back(make_pair(i,st.back().first));
                    else
                        arr[st.back().first]++;
                        i++;
                }

            }
            int ans=0;
            for(i=0;i<l;i++)
            {
                ans=max(ans,dist[i]);
                //cout<<dist[i]<<" ";
            }
            //cout<<endl;
            cout<<ans<<endl;
        }
    }
}
