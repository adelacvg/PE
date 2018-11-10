#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ax=1,ay=1;
    for(int n=1;n<=9;n++)
    {
        for(int y=1;y<n;y++)
        {
            for(int x=1;x<y;x++)
            {
                if(9*x*(y-n)==n*(x-y))
                {
                    ax*=x;
                    ay*=y;
                }
            }
        }
    }
    ay/=__gcd(ax,ay);
    cout<<ay;
}
