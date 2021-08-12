#include<iostream>
#include<iomanip>
#include<cmath>
int main()
{
    double ans=0;
    int round=0;
    for(;;)
    {
        auto t = 1-std::pow((1-std::pow(0.5,round)),32);
        std::cout<<t<<'\n';
        if(t>1e-12)
        {
            round++;
            ans+=t;
            std::cout<<ans<<'\n';
            continue;
        }
        break;
    }
    std::cout<<std::fixed<<std::setprecision(10)<<ans<<'\n';
}
