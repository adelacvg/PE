#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull a,b,c,d,e,f;
    for(int i=4;;i++)
    {
        a= i*i;
        for(int j=3;j<i;j++)
        {
        
            c=j*j;
            f=a-c;
            if(f<=0||(int)sqrt(f)*sqrt(f)!=f) continue;

            for(ull k=((j%2)?1:2);k<j;k+=2)
            {
                d=k*k;
                e=a-d;
                b=c-e;
                if(b<=0||e<=0||(int)sqrt(b)*sqrt(b)!=b||(int)sqrt(e)*sqrt(e)!=e)
                    continue;
                cout<<(d+c)/2+(e+f)/2+(c-d)/2;
                return 0;
            }
        }
    }
}
