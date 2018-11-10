#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans=0,x=0,y=-1;
    for(int i=0;i<12;i++)
    {
        long long xx=0,yy=0;
        xx=(-9)*x+4*y-4;
        yy=20*x+(-9)*y+8;
        x=xx;
        y=yy;
        ans+=abs(yy);
    }
    cout<<ans;
}
//https://www.alpertron.com.ar/QUAD.HTM
