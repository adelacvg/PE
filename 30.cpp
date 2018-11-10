#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    for(int i=2;i<=1000000;i++)
    {
        int t=i;
        int sum=0;
        while(t)
        {
            sum+=pow(t%10,5);
            t/=10;
        }
        if(sum==i)
            ans+=i;
    }
    cout<<ans;
}
