#include<bits/stdc++.h>
using namespace std;
int fac[9];

void init()
{
    fac[0]=1;
    for(int i=1;i<=9;i++)
    {
        fac[i]=i*fac[i-1];
    }
}

int f(int x)
{
    int tmp=0;
    int xx=x;
    while(x)
    {
        tmp+=fac[x%10];
        x/=10;
    }
    if(tmp==xx)
        return 1;
    else
        return 0;
}

int main()
{
    init();
    int ans=0;
    for(int i=10;i<=1e8;i++)
    {
        if(f(i))
            ans+=i;
    }
    cout<<ans;
}
