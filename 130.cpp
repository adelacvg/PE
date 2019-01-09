#include<bits/stdc++.h>
using  namespace std;
int notprime[1000010];
void sieve()
{
    for(long long i=2;i<=1000010;i++)
    {
        if(!notprime[i])
        {
            for(long long j=i*i;j<=1000010;j+=i)
            {
                notprime[j]=1;
            }
        }
    }
}
long long A(long long n)
{
    if(__gcd((long long)10,n)!=1)
        return 0;
    long long t=1,k=1;
    while(t!=0)
    {
        t=(t*10+1)%n;
        k++;
    }
    return k;
}

int main()
{
    sieve();
    int M=25;
    int found=0;
    int n=1;
    long long ans=0;
    while(found<M)
    {
        n++;
        if(!notprime[n])continue;
        long long t=A(n);
        if(t!=0&&((n-1)%t==0))
        {
            ans+=n;
            found++;
        }
    }
    cout<<ans<<endl;
}
