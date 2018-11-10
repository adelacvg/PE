#include<iostream>
#include<cmath>
using namespace std;
int p[10]={2,3,5,7,11,13,17,19};
int cnt[10];
int main()
{
    for(int i=2;i<=20;i++)
    {
        for(int j=0;j<=7;j++)
        {
            int t=0;
            int tmp=i;
            while(tmp%p[j]==0)
            {
                tmp/=p[j];
                t++;
            }
            cnt[j]=max(cnt[j],t);
        }
    }
    int ans=1;
    for(int i=0;i<8;i++)
    {
        cout<<cnt[i]<<'\n';
        ans*=pow(p[i],cnt[i]);
    }
    cout<<ans;
}
