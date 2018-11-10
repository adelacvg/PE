#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[1000010];
int prefix[1000010];
vector<ull> v;
void init()
{
    for(ull i=2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            v.push_back(i);
            for(ull j=i*i;j<=1000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
}
int main()
{
    int ans=0;
    int cnt=0;
    int x=0;
    init();
    for(int i=1;i<v.size();i++)
    {
        v[i]+=v[i-1];
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            x++;
            if(v[i]-v[j]>1000000)
                break;
            if(flag[v[i]-v[j]]==0)
            {
                if(i-j>cnt)
                {
                    cnt=i-j;
                    ans=v[i]-v[j];
                }
            }
        }
    }
    cout<<v.size()<<'\n';
    cout<<x<<'\n';
    cout<<ans;
}
