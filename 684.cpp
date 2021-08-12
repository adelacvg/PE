#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
// # Define s(n) to be the smallest number that has a digit sum of n.
// # For example s(10)=19.
// # Let S(k) = s(1) + ... + s(k). You are given S(20) = 1074.
// #
// # Further let f_i be the Fibonacci sequence defined by
// # f_0 = 0, f_1 = 1 and f_i = f_{i−2} + f_{i−1} for all i >= 2.
// #
// # Find S(f_2) + ... + S(f_90). Give your answer modulo 1000000007.

// # THEORY:
// #
// # For all n, all digits of s(n) except the leading digit will be 9.
// # Hence s(9r+i) = i * 10^r + (10^r - 1) = (i+1) * 10^r - 1, for i < 9.
// # So you can sum numbers in clusters of nine:
// # s(9r) + s(9r + 1) + ... + s(9r + 8) = 45 * 10^r - 9.
// # So, s(0) + ... + s(9r + 8) = 45 * (1 + 10 + ... + 10^r) - 9r - 9
// #                            = 5 * (10^(r+1) - 1) - 9r - 9.
// # If n = 9d + r, then the remaining terms are
// # (0 + ... + r) * 10^d + (r + 1) * (10^d - 1)
// # = r * (r + 1) / 2 * 10^d + (r + 1) * 10^d - r - 1.
// # Summing these all together yields
// # S(9d + r) = (5 * (r + 1)(1 + r/2)) * 10^d - n - 6.
void s(long long n, vector<long long>& sv)
{
    long long tmp=(n%9)*1ll;
    n-=tmp;
    for(int j=0;j<=(n/9);j++)
        tmp=(tmp*10+9)%mod;
    sv.emplace_back(tmp);
}
long long qpow(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b&1)
            c=(c*(a%mod))%mod;
        a=(a*(a%mod))%mod;
        b>>=1;
    }
    return c;
}
long long S(long long n)
{
    long long d=n/9;
    long long r=n%9;
    // cout<<d<<" "<<r<<endl;
    // cout<<qpow(10,d)<<endl;
    return ((5+r*(r+1)/2+r+1)*qpow(10,d)-n-6)%mod;
}

int main()
{
    array<long long,100> a{0,1};
    long long ans=0;
    cout<<S(20)<<endl;
    for(int i=2;i<=90;i++)
    {
        a[i]=a[i-1]+a[i-2];
        // cout<<S(a[i])<<endl;
        ans=(ans+S(a[i]))%mod;
    }
    while(ans<0)ans+=mod;
    cout<<ans<<endl;
}
