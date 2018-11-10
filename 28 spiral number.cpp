#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=1;
    int x=1;
    for(int i=2;i<=1000;i+=2)
    {
        for(int j=1;j<=4;j++)
        {
            x+=i;
            ans+=x;
        }
    }
    cout<<ans;
}
