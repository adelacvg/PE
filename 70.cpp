#include<bits/stdc++.h>
using namespace std;
int phi[10000010];
bool flag[10000010];
int fac[100];
vector<int> p;
void sieve(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!flag[i])
        {
            phi[i]=i-1;
            p.push_back(i);
        }
        for(auto j:p)
        {
            if(j*i>n)
                break;
            flag[j*i]=1;
            if(i%j==0)
                phi[i*j]=j*phi[i];
            else
                phi[i*j]=(j-1)*phi[i];
        }
    }
    fac[1]=1;
    for(int i=2;i<=10;i++)
        fac[i]=fac[i-1]*i;
}
bool equal_permu(int n)
{
    int l1=0,l2=0;
    int t1=n,t2=phi[n];
    while(t1){t1/=10;l1++;}
    while(t2){t2/=10;l2++;}
    if(l1!=l2)
        return 0;
    t1=n,t2=phi[n];
    map<int,int>m1,m2;
    while(t1)
    {
        m1[t1%10]++;
        m2[t2%10]++;
        t1/=10;
        t2/=10;
    }
    t1=n;
    while(t1)
    {
        if(m1[t1%10]!=m2[t1%10])
            return 0;
        t1/=10;
    }
    return 1;
}

int main()
{
    sieve(10000000);
    int ans=0;
    double t=100000000;
    for(int i=2;i<10000000;i++)
    {
        if(equal_permu(i))
        {
            if(1.0*i/phi[i]<t)
            {
                ans=i;
                t=1.0*i/phi[i];
            }
        }
    }
    cout<<ans<<endl;
}
