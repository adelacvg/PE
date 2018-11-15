#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
vector<long long> v;
int main()
{
    int n=1500000;
    int ans=0;
    for(int i=2;2*i*i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(((i+j)%2)&&__gcd(i,j)==1)
            {
                long long a=i*i+j*j;
                long long b=2*i*j;
                long long c=i*i-j*j;
                long long sum=a+b+c;
                v.push_back(sum);
            }
        }
    }
    for(auto i:v)
    {
        long long sum=i;
        while(sum<=n)
        {
            m[sum]++;
            sum+=i;
        }
    }

    for(auto i:m)
    {
        if(i.second==1)
            ans++;
    }
    cout<<ans<<endl;
}
