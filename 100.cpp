#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull x=1,y=0;
    while(x+y<1e12)
    {
        ull tx=5*x+2*y-2;
        ull ty=2*x+y-1;
        x=tx;
        y=ty;
    }
    cout<<x<<endl;
}
