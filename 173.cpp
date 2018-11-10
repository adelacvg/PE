#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull f(ull n,ull k)
{
    return (ull)(((double)n/k-k)/2);
}
int main()
{
    ull ans =0;
    ull n=1000000;
    for(ull i=2;i*i<=n;i+=2)
    {
        ull x = f(n,i);
        if(x>0)
            ans+=x;
    }
    cout<<ans;
}
