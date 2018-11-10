#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=1,b=3,c=4000,d=11999,n=12000;
    int ans = 0;
    while(!(c==1&&d==2))
    {
        int k=(b+n)/d;
        int p=k*c-a;
        int q=k*d-b;
        a = c,b = d,c = p,d = q;
        ans++;
    }
    cout<<ans;
}
