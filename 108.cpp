#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<ull> v;
vector<bool> vis(1000000000,0);
void sieve()
{
    v.push_back(2);
    for(ull i=3;i<=1000000;i+=2)
    {
        if(!vis[i])
        {
            v.push_back(i);
            for(ull j=i*i;j<=1000000;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
ull f(ull n)
{
    ull ans=1;
    for(auto i:v)
    {
        if(i*i>n||n==1)
            break;
        ull cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        ans*=(2*cnt+1);
    }
    if(n>1)
        ans*=3;
    return ans;
}
int main()
{
    ull n=1000;
    sieve();
    while((f(n)+1)/2<1000)
        n++;
    cout<<n;
}
