#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int dot(pair<int,int> a,pair<int,int> b)
{
    return a.first*b.first+a.second*b.second==0;
}
bool isright(auto a,auto b)
{
    if(dot(a,b)||dot(a,{-a.first+b.first,-a.second+b.second})||dot(b,{a.first-b.first,a.second-b.second}))
            return 1;
}
int main()
{
    int M=50;
    for(int i=0;i<=M;i++)
    {
        for(int j=0;j<=M;j++)
        {
            v.push_back({i,j});
        }
    }
    int ans=0;
    for(auto i:v)
    {
        for(auto j:v)
        {
            if(i==j||i==make_pair(0,0)||j==make_pair(0,0))
            continue;
            if(isright(i,j))
            {
                ans++;
                //cout<<i.first<<" "<<i.second<<" "<<j.first<<" "<<j.second<<endl;
            }
        }
    }
    cout<<ans/2;
}
