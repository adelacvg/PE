#include<iostream>
#include<vector>
#include<map>
using ull=unsigned long long;
std::vector<ull> p;
std::vector<bool> flag(20000010,1);
void sieve(unsigned long long n)
{
    for(auto i=2ull;i<=n;i++)
    {
        if(flag[i])
        {
            p.push_back(i);
        }
        for(auto j=i*i;j<=n;j+=i)
        {
            flag[j] = 0;
        }
    }
}
std::map<ull,ull> get_cnt(ull n)
{
    std::map<ull,ull> cnt;
    for(auto i:p)
    {
        auto t = i;
        while(t<=n)
        {
            cnt[i]+=n/t;
            t*=i;
        }
    }
    return cnt;
}
int main()
{
    int a = 20'000'000;
    int b = 15'000'000;
    sieve(a);
    auto cnt1 = get_cnt(a);
    auto cnt2 = get_cnt(b);
    auto cnt3 = get_cnt(a-b);
    unsigned long long sum = 0;
    for(auto i:cnt1)
    {
        sum+=i.first*(i.second-cnt2[i.first]-cnt3[i.first]); 
    }
    std::cout<<sum<<'\n';    
}
