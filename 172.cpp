#include<bits/stdc++.h>
using namespace std;
long long int fac[100];
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=30;i++)
    {
        fac[i]=fac[i-1]*i;
    }
}
int main()
{
    long long int ans=0;
    init();
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=10;k++)
            {
                if(3*i+2*j+k==18&&i+j+k<=10)
                {
                   long long int a = fac[10]/fac[i]/fac[j]/fac[k]/fac[10-i-j-k];
                   long long int b = fac[18];
                   for(int t=1;t<=i;t++)
                       b/=fac[3];
                   for(int t=1;t<=j;t++)
                       b/=fac[2];
                   ans+=a*b;
                }
            }
        }
    }
    cout<<ans*9/10;
}
