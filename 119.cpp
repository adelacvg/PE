#include<bits/stdc++.h>
using namespace std;
set<__int64> s;
int main()
{
    for(int i=7;i<=100;i++)
    {
        __int64 n=i,d,t;
        for(int j =1;j<=12;j++)
        {
            n*=i;
            t=n;
            d=0;
            while(t)
            {
                d+=t%10;
                t/=10;
            }
            if(d==i)
                s.insert(n);
        }
    }
    for(auto i: s)
    {
        cout<<i<<'\n';
    }
}
