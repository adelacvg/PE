#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    for(int i=2;i<=10000;i++)
    {
        if(sqrt(i)*sqrt(i)==i)
            continue;
        int s=i,a=floor(sqrt(s)),m=0,d=1;
        int cnt=0;
        while(1)
        {
            m=a*d-m;
            d=(s-m*m)/d;
            a=floor((sqrt(s)+m)/d);
            cnt++;
            if(a==2*floor(sqrt(s)))
                break;
        }
        ans+=cnt%2;
    }
    cout<<ans<<endl;
}
