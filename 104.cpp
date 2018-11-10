#include<bits/stdc++.h>
using namespace std;
map<int,int>vis;
int main()
{
    long long int ans=0;
    int n=3;
    long long int a=1,b=1,c=0;
    while(1)
    {
        vis.clear();
        int f1=1,f2=1;
        c=(a+b)%1000000000;
        a=b,b=c;
        double x = -0.5*log10(5)+n*log10((1+sqrt(5))/2);
        long long int t=c;
        while(t)
        {
            if(vis[t%10])
            {
                f1=0;
                break;
            }
            vis[t%10]++;
            t/=10;
        }
        if(vis.size()!=9||vis[0])
            f1=0;
        x-=floor(x);
        t = int(pow(10,x)*100000000);
        vis.clear();
        while(t)
        {
            if(vis[t%10])
            {
                f2=0;
                break;
            }
            vis[t%10]++;
            t/=10;
        }
        if(vis.size()!=9||vis[0])
            f2=0;
        if(f1&&f2)
        {
            cout<<n;
            break;
        }
        n++;
    }
}
