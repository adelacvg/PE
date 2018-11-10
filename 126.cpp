#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int m[20010];
ull f(ull x,ull y,ull z,ull n)
{
    return 2*(x*y+x*z+y*z)+4*(n-1)*(x+y+z+n-2);
}
int main()
{
    for(ull x=1;f(x,x,x,1)<=20000;x++)
    {
        for(ull y=x;f(x,y,x,1)<=20000;y++)
        {
            for(ull z=y;f(x,y,z,1)<=20000;z++)
            {
                for(ull n=1;f(x,y,z,n)<=20000;n++)
                {
                    m[f(x,y,z,n)]++;
                }
            }
        }
    }
    for(int i=1;i<=20000;i++)
    {
        if(m[i]==1000)
        {
            cout<<i;
            return 0;
        }
    }
}
