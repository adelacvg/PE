#include<iostream>
#include<vector>
#include<algorithm>
unsigned long long solve(unsigned long long a,
        unsigned long long b,unsigned long long mod)
{
    unsigned long long ret = 1;
    while(b)
    {
        if(b&1)
            ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    unsigned long long a = 1777;
    unsigned long long b = 1855;
    unsigned long long last=0,res=1;
    for(auto i=1ull;i<=b;i++)
    {
        res=solve(a,res,100000000);
        if(res==last)
        {
            break;
        }
        last = res;
        std::cout<<res<<'\n';
    }
    std::cout<<res<<'\n';
}
