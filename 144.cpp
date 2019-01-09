#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    double xa=0.0,ya=10.1,xo=1.4,yo=-9.6;
    while(xo>0.01||xo<-0.01||yo<0)
    {
        double slopea = (yo-ya)/(xo-xa);

        double slopeo = -4*xo/yo;

        double tana = (slopea - slopeo)/(1+slopea*slopeo);
        double slopeb = (slopeo - tana)/(1+tana*slopeo);

        double interceptb = yo - slopeb*xo;

        double a = 4+ slopeb*slopeb;
        double b = 2*slopeb*interceptb;
        double c = interceptb*interceptb - 100;

        double ans1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
        double ans2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

        xa=xo;
        ya=yo;

        xo = abs(ans1-xo)>abs(ans2-xo)?ans1:ans2;
        yo = slopeb*xo + interceptb;

        ans++;
    }
    cout<<ans;
}
