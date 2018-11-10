#include<cstdio>
#include<iostream>
using namespace std;
#define ull unsigned long long
int flag[10000010];

int main()
{
    for(ull i=2;i<=10000000;i++)
    {
        for(ull j=i*i;j<=10000000;j+=i)
        {
            flag[j]=1;
        }
    }
    int cnt=0;
    ull ans=0;
    for(ull i=2;i<2000000;i++)
    {
        if(!flag[i])
        {
            cnt++;
            ans+=i;
        }
    }
    cout<<cnt<<'\n';
    cout<<ans;
}

