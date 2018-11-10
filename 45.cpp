#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int f(ull x)
{
    double n = (1+sqrt(1+24*x))/6.0;
    return n==(ull)n;
}
int main()
{
    ull i=144;
    ull ans;
    while(1)
    {
        ull x = i*(2*i-1);
        if(f(x))
        {
            ans=x;
            break;
        }
        i++;
    }
    cout<<ans;
}
