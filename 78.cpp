#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> par(1000010,0);
vector<ll> k;
void init()
{
    for(int i=1;i<=1000010;i++)
    {
        int t=i;
        k.push_back(t*(3*t-1)/2);
        t*=-1;
        k.push_back(t*(3*t-1)/2);
    }
}
int main()
{
//#define test
    init();
    ll mod=1e6;
    ll n=1;
    par[0]=1;
#ifndef test
    while(n)
    {
        int flag=0;
        for(auto i:k)
        {
            if(n-i<0)
                break;
            if(flag==0||flag==1)
            {
                par[n]=(par[n]+par[n-i])%mod;
            }
            else
            {
                par[n]=(par[n]-par[n-i]+mod)%mod;
            }
            flag=(flag+1)%4;
        }
        if(par[n]%mod==0)
        {
            cout<<n<<endl;
            break;
        }
        n++;
    }
    return 1;
#endif
}
