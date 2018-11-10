#include<bits/stdc++.h>
using namespace std;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37};
map<long double, vector<unsigned int>> v = {{1,vector<unsigned int>(12,0)}};
int main()
{
    int n=4000000;
    while(1)
    {
        auto cur = v.begin();
        auto val = cur->first;
        auto exp = cur->second;
        cout<<val<<'\n';
        v.erase(cur);
        unsigned long long uni = 1;
        for(auto i : exp)
            uni*=2*i+1;
        uni=(uni+1)/2;
        if(uni>=n)
        {
            cout<<fixed<<setprecision(0)<<val;
            break;
        }
        for(unsigned int i=0;i<exp.size();i++)
        {
            exp[i]++;
            val*=p[i];
            v[val]=exp;
        }
    }
}
