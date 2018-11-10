#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull N = 100000000;
bool flag[N+100];
vector<ull> v;
//vector<vector<int>> d(N,vector<int>(100));
map<ull,ull> m;
void sieve()
{
    for(ull i=2;i<=N;i++)
    {
        if(!flag[i])
        {
            v.push_back(i);
            //d[i].push_back(i);
            for(ull j=i*i;j<=N;j+=i)
            {
                flag[j]=1;
                //d[j].push_back(i);
            }
        }
    }
}

void init()
{
    for(auto i:v)
    {
        ull j = i;
        while(j<=N)
        {
            ull t=i;
            ull fac=t;
            while(1)
            {
                if(fac%j==0)
                {
                    m[j]=t;
                    break;
                }
                t+=i;
                fac=(fac*t)%j;
            }
            j*=i;
        }
    }
}

inline ull s(ull x)
{
    ull ans=0;
    for(auto i:v)
    {
        if(i*i>x)
            break;
        if(x%i==0)
        {
            ull t=1;
            while(x%i==0)
            {
                x/=i;
                t*=i;
            }
            ans=max(ans,m[t]);
        }
    }
    if(x>1)
    ans=max(ans,x);
    return ans;
}

int main()
{
    ull ans=0;
    sieve();
    init();
    for(int i=2;i<=N;i++)
    {
        ans+=s(i);
    }
    cout<<ans;
}
