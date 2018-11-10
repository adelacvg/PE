#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<ull> v;
int main()
{
    auto n = 1e12;
    ull ans=1;
    for(ull i=2;i*i<n;i++)
    {
        auto t = i*i;
        auto j = i+1;
        while(j+t<n)
        {
            j+=t;
            t*=i;
            v.push_back(j);
        }
    }
    sort(v.begin(),v.end());
    auto last = unique(v.begin(),v.end());
    v.erase(last,v.end());

    for(auto i : v)
        ans+=i;
    cout<<ans;
}
