#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull comb(ull a,ull b)
{
    if(2*a<b)
        return 0;
    if(a>=b)
        return b/2;
    return a-(b-1)/2;
}
vector<ull> count(ull limit)
{
    vector<ull> ans(limit+1,0);

    for(ull m=1;m<=sqrt(2*limit);m++)
    {
        for(ull n=1;n<m;n++)
        {
            if(m%2==n%2)
                continue;
            if(__gcd(m,n)!=1)
                continue;

            auto x=m*m-n*n;
            auto y=2*m*n;
            for(ull k=1;k*x<=limit;k++)
                ans[k*x]+=comb(k*x,k*y);
            for(ull k=1;k*y<=limit;k++)
                ans[k*y]+=comb(k*y,k*x);
        }
    }
    return ans;
}
int main()
{
    auto ans=count(1000000);
    vector<ull> total;
    ull sum=0;
    for(auto i: ans)
    {
        sum+=i;
        total.push_back(sum);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<total[x]<<endl;
    }
}
