#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<pair<ull,ull>> rad(120010,make_pair(0,0));
vector<ull> r(120010,1);
vector<bool> isprime(120010,1);
void sieve()
{
    for(int i=1;i<120000;i++)
    {
        rad[i]={1,i};
    }
    for(ull i=2;i<120000;i++)
    {
        if(isprime[i])
        {
            for(ull j=i;j<120000;j+=i)
            {
                rad[j].first*=i;
                r[j]*=i;
                isprime[j]=0;
            }
        }
    }
}
int main()
{
    sieve();
    sort(rad.begin()+1,rad.begin()+120000);
    ull ans=0;
    int N = 120000;

    for(ull c=3;c<N;c++)
    {
        for(int a=1;a<N;a++)
        {
            if(rad[a].first*r[c]*2>c)
                break;
            if(rad[a].second*2+1>c)
                continue;
            ull b=c-rad[a].second;
            if(r[b]*r[c]*rad[a].first<c&&__gcd(r[b],rad[a].first)==1)
                ans+=c;
        }
    }
    cout<<ans;
}
