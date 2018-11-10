#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main()
{
    long long int res=0;
    for(int i=3;i<=1000;i++)
    {
        m.clear();
        int n=3;
        long long int ans=2;
        while(1)
        {
            long long int t=(2*i*n)%(i*i);
            if(m[t])
                break;
            ans=max(ans,t);
            m[t]++;
            n+=2;
        }
        res+=ans;
    }
    cout<<res;
}
