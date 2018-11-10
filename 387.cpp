#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull power(ull x, ull y, ull p) 
{ 
    ull res = 1;
    x = x % p;
    while (y) 
    {
        if (y&1) 
            res = (res*x) % p; 
        y>>=1;
        x=(x*x) % p; 
    }
    return res;
} 
bool miillerTest(ull d, ull n) 
{ 
    ull a = 2 + rand() % (n - 4); 
    ull x = power(a, d, n); 
    if (x == 1  || x == n-1) 
       return true; 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
    return false; 
} 
bool isPrime(ull n, ull k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
    ull d = n - 1;
    while (d % 2 == 0) 
        d /= 2;
    for (ull i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
    return true; 
}
int main()
{
    ull ans=0;
    map<ull,ull> strongv[20];
    vector<pair<ull,ull>> v;
    for(int i=1;i<=9;i++)
        v.push_back({i,i});
    int l=1;
    while(l++)
    {
        if(l==4)break;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=9;j++)
            {
                string s = to_string(v[i].first)+to_string(j);
                ull t=stoll(s);
                ull digsum=v[i].second+j;
                if(t%digsum==0)
                {
                    v.push_back({t,digsum});
                    if(isPrime(t/digsum,4))
                        strongv[l+1][t]++;
                }
                if(isPrime(t,4)&&strongv[l][v[i].first])
                    ans+=t;
            }
        }
        v.erase(v.begin(),v.begin()+n);
    }
    cout<<ans;
}
