#include<bits/stdc++.h>
using namespace std;
long long int phi[1000010];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        phi[i] = i;
    }
    for(int p = 2;p<=n;p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(int i=2*p;i<=n;i+=p)
            {
                phi[i] = phi[i]*(p-1)/p; 
            }
        }
    }
    /*
    for(int i=1;i<=100;i++)
    {
        cout<<phi[i]<<'\n';
    }
    */
}
int main()
{
    init(1000000);
    long long int ans=1;
    for(int i=1;i<=1000000;i++)
    {
        ans += phi[i];
    }
    cout<<ans-2;
}
