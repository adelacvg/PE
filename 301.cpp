#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int ans=0;
    for(ull i = 1;i<=1<<30;i++)
    {
        if((i^(i<<1)^(i<<4-i))==0)
        {
            ans++;
        }
    }
    cout<<ans;
}
