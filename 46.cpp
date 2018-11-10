#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[1000010];
vector<ull> v;
void init()
{
    for(ull i=2;i<=1000000;i++)
    {
        if(!flag[i])
            v.push_back(i);
        for(ull j=i*i;j<=1000000;j+=i)
        {
            flag[j]=1;
        }
    }
}
int f(int n)
{
    return sqrt(n)==(int)sqrt(n);
}
int main()
{
    int ans=0;
    init();
    int i=9;
    while(1)
    {
        int ff=1;
        if(i%2==1&&flag[i]==1)
        {
            for(auto j:v)
            {
                if(j>i)
                    break;
                if(f((i-j)/2))
                {
                    ff=0;
                    break;
                }
            }
            if(ff)
                ans=i;
        }
        i++;
        if(ans)
            break;
    }
    cout<<ans;
}
