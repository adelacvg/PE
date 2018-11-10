#include<bits/stdc++.h>
using namespace std;
vector<int> p;
map<int,int> m;

void esieve()
{
    m[0]=m[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(m[i]==0)
        {
            p.push_back(i);
            for(unsigned long long j=i*i;j<=1000000;j+=i)
            {
                m[j]=1;
            }
        }
    }
}

int f(int n)
{
    int res=n;
    for(auto i:p)
    {
        if(i>sqrt(n))
            break;
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            res-=res/i;
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}
int main()
{
    esieve();
    double r=0;
    int ans;
    for(int i=1;i<=1000000;i++)
    {
        double x = 1.0*i/f(i);
        if(x>r)
        {
            ans=i;
            r=x;
        }
    }
    cout<<ans;
}
