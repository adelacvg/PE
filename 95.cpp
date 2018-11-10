#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000100];
map<int,int> m;
void init()
{
    for(int i=1;i<=1000000;i++)
    {
        for(int j=2*i;j<=1000000;j+=i)
        {
            v[j].push_back(i);
        }
    }
}
int main()
{
    init();
    int ans=0;
    int res;
    for(int i=1;i<=1000000;i++)
    {
        m.clear();
        int t=i;
        int cnt=0;
        while(1)
        {
            if(t==1||t>1000000||m[t]&&t!=i)
                break;
            if(m[t]&&t==i)
            {
                if(cnt>ans)
                {
                    res=i;
                    ans=max(ans,cnt);
                }
                break;
            }
            m[t]=1;
            int tt=0;
            for(auto j:v[t])
                tt+=j;
            t=tt;
            cnt++;
        }
    }
    cout<<res;
}
