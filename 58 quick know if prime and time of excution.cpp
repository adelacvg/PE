#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[1000010];
int f(ull n)//352ms
{
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    if(n<9) return 1;
    if(n%3==0) return 0;

    ull x=5;
    while((x*x)<=n)
    {
        if(n%x==0) return 0;
        if(n%(x+2)==0) return 0;
        x+=6;
    }
    return 1;
}
int f1(ull n)//2245ms
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int start=clock();
    double r=1;
    int d=0,x=1,ans=1;
    int a=0,b=1;
    while(r>=0.1)
    {
        ans+=2;
        b+=4;
        d+=2;
        for(int j=1;j<=4;j++)
        {
            x+=d;
            if(f(x))
                a++;
        }
        r=1.0*a/b;
    }
    cout<<ans<<'\n';
    int stop=clock();
    cout<<(stop-start)/double(CLOCKS_PER_SEC)*1000<<'\n';
}
