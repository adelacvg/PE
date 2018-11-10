#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<bool> flag(400000010,0);
vector<ull>p;
ull power(ull x, ull y, ull m)
{ 
    ull res = 1;
    x = x % m; 
    while (y) 
    {
        if (y&1) 
            res = (res*x) % m; 
        y>>=1;
        x = (x*x) % m;
    } 
    return res; 
} 
  
bool miillerTest(ull d, ull n) 
{
    srand(time(0));
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
    int d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false;
    return true;
} 
int is_prime(int a,int b)
{
    int l1=0,l2=0;
    ull t1=a,t2=b;
    while(t1)
    {l1++;t1/=10;}
    while(t2)
    {l2++;t2/=10;}
    cout<<a<<" "<<b<<" "<<a*pow(10,l2)+b<<" "<<b*pow(10,l1)+a<<endl;
    if(!isPrime(a*pow(10,l2)+b,4)||!isPrime(b*pow(10,l1)+a,4))
        return 0;
    return 1;
}
int main()
{
    for(unsigned long long i=2;i<=30000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
            for(unsigned long long j=i*i;j<=30000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    ull ans=10000000;
    int n=p.size();
    for(int a=0;a<n;a++)
    {
        if(p[a]*5>=ans)break;
        for(int b=a+1;b<n;b++)
        {
            if(p[a]+p[b]*4>=ans)break;
            if(!is_prime(p[a],p[b]))
                continue;
            for(int c=b+1;c<n;c++)
            {
                if(p[a]+p[b]+3*p[c]>=ans)break;
                if(!is_prime(p[a],p[c])||!is_prime(p[b],p[c]))
                    continue;
                for(int d=c+1;d<n;d++)
                {
                    if(p[a]+p[b]+p[c]+2*p[d]>=ans)break;
                    if(!is_prime(p[d],p[a])||!is_prime(p[d],p[b])||!is_prime(p[d],p[c]))
                        continue;
                    for(int e=d+1;e<n;e++)
                    {
                        if(p[a]+p[b]+p[c]+p[d]+p[e]>=ans)
                            break;
                        if(!is_prime(p[e],p[a])||!is_prime(p[e],p[b])||!is_prime(p[e],p[c])||!is_prime(p[e],p[d]))
                            continue;
                        cout<<p[a]<<" "<<p[b]<<" "<<p[c]<<" "<<p[d]<<" "<<p[e]<<endl;
                        ans=min(p[a]+p[b]+p[c]+p[d]+p[e],ans);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
