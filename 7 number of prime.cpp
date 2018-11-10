#include<cstdio>
#include<iostream>
using namespace std;
#define ull unsigned long long
int flag[2000010];

int main()
{
    for(ull i=2;i<=2*1000000;i++)
    {
        if(!flag[i])
        {
            for(ull j=i*i;j<=2*1000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    int cnt=0;
    int ans;
    for(ull i=2;i<=2000000;i++)
    {
        if(!flag[i])
        {
            cnt++;
            if(cnt==10001)
                ans=i;
        }
    }
    cout<<ans;
}
