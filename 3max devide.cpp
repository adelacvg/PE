#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long long x = 600851475143;
    unsigned long long ans=0;
    for(int i=3;i<=sqrt(600851475143);i++)
    {
        if(x%i==0)
        {
            x/=i;
            ans=i;
        }
    }
    ans=max(ans,x);
    cout<<ans;
}
