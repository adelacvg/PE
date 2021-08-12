#include<iostream>
#include<vector>
using ull = unsigned long long;
std::vector<bool> flag(1000010,1);
std::vector<ull> p;
void sieve(ull n)
{
    flag[0]=flag[1]=0;
    for(auto i = 2ull;i<=n;i++)
    {
        if(flag[i])
        {
            p.push_back(i);
        }
        for(auto j=i*i;j<=n;j+=i)
        {
            flag[j]=0;
        }
    }
}
int main()
{
    sieve(1000000);
    int ans=0;
    for(auto i=1ull;;i++)
    {
        auto t = (i+1)*(i+1)*(i+1)-i*i*i;
        if(t>1000000)
            break;
        if(flag[t])
            ans++;
    }
    std::cout<<ans<<'\n';
}
