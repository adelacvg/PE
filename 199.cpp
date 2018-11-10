#include<bits/stdc++.h>
const double pi=acos(-1);
using namespace std;
double area(double r)
{
    return pi*r*r;
}
double cal(double k1,double k2,double k3,int depth)
{
    auto k4 = k1+k2+k3+2*sqrt(k1*k2+k1*k3+k2*k3);
    auto r = 1/k4;
    auto a = area(r);
    if(depth==1)
        return a;
    return (a + cal(k1,k2,k4,depth-1)+cal(k2,k3,k4,depth-1)+cal(k1,k3,k4,depth-1));

}
int main()
{
    auto outk = 3-2*sqrt(3);
    auto outr = -1/outk;
    auto ink = 1.0;
    auto inr = 1/ink;
    auto initial = 3*area(inr);
    auto vshape = cal(outk,ink,ink,10);
    auto middle = cal(ink,ink,ink,10);
    auto ans = initial+3*vshape+middle;
    ans/=area(outr);
    ans=1-ans;
    cout<<ans;
}
