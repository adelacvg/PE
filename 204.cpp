#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<bool> isprime(110,1);
vector<ull> p;
void sieve()
{
    for(ull i=2;i<=100;i++)
    {
        if(isprime[i])
        {
            p.push_back(i);
            for(ull j=i*i;j<=100;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
}
ull search(ull product=1,ull minprime=0)
{
    ull res=1;
    for(int i=minprime;i<p.size();i++)
    {
        if(product*p[i]>1e9)
            break;
        res+=search(product*p[i],i);
    }
    return res;
}
int main()
{
    sieve();
    ull ans = search();
    cout<<ans;
}
