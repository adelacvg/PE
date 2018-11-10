#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int ans[1000010],m[1000010];
void init()
{
    for(int i=2;i*i<=1000000;i+=2)
    {   
        int j = 2;
        while(true)
        {
            int x = i*(i+j);
            if(x>1e6)
                break;
            m[x]++;
            j+=2;
        }
    }
}
int main()
{
    init();
    for(int i=1;i<=1000000;i++)
    {
        if(m[i]<=10&&m[i])
            ans[i]=ans[i-1]+1;
        else
            ans[i]=ans[i-1];
    }
    cout<<ans[1000000];
}
