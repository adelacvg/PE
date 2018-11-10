#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull hs(ull x)
{
    ull ans=0;
    while(x)
    {
        auto digit = x%10;
        x/=10;

        auto bits = 6;
        ans+=1ULL<<(bits*digit);
    }
    return ans;
}
int main()
{
    ull m = 10000;
    ull n = 5;
    map<ull, vector<ull>> match;
    for(int i=1;i<m;i++)
    {
        auto cube = (ull) i*i*i;
        match[hs(cube)].push_back(i);
    }
    set<ull> sm;
    for(auto i : match)
    {
        if(i.second.size() == n)
        {
            sm.insert(i.second.front());
        }
    }
    for(auto i:sm)
    {
        cout<<i*i*i<<'\n';
    }
}
