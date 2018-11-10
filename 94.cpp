#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull x=2,y=1;
    ull limit = 1e9;
    ull ans=0;
    while(1)
    {
        ull a3 = 2*x-1;
        ull area3 = y*(x-2);
        if(a3>limit)break;
        if(a3>0&&area3>0&&a3%3==0&&area3%3==0)
            ans+=a3+1;
        a3=2*x+1;
        area3=y*(x+2);
        if(a3>0&&area3>0&&a3%3==0&&area3%3==0)
            ans+=a3-1;
        ull tx=2*x+3*y;
        ull ty=x+2*y;

        x=tx,y=ty;
    }
    cout<<ans;
}
