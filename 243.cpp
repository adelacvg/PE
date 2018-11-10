#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<ull> phi(10000000,0),prime;
vector<bool> isprime(10000000,1);
void sieve()
{
    phi[1]=1;
    for(int i=2;i<=1e7;i++)
    {
        if(isprime[i])
        {
            phi[i]=i-1;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=1e7;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
}
int main()
{
    sieve();
    ull n=1,m=1;
    for(auto i:prime)
    {
        n*=i;
        m*=phi[i];
        if(m*94744<15499*(n-1))
        {
            n/=i;
            m/=phi[i];
            ull tn,tm;
            for(int j=1;j<=phi[i];j++)
            {
                tn=n*j;
                if(j!=phi[i])
                    tm=m*j;
                else
                    tm=m*phi[j];
                if(tm*94744<15499*(tn-1))
                    break;
            }
            cout<<tn<<endl;
            break;
        }
    }
}
