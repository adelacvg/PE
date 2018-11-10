#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int cnt[1000010];
int flag[1000010];
void init()
{
    for(ull i=2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            for(ull j=2*i;j<=1000000;j+=i)
            {
                flag[j]=1;
                cnt[j]++;
            }
        }
    }
}

int main()
{
    int ans;
    init();
    for(int i=1;i<=1000000;i++)
    {
        if(cnt[i]==4&&cnt[i+1]==4&&cnt[i+2]==4&&cnt[i+3]==4)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
}
