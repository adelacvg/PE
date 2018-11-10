#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans;
    for(int i=1;i<=floor(3*1000000/7);i++)
    {
        if((7*i+1)%3==0)
        {
            int j=(7*i+1)/3;
            if(__gcd(i,j)==1)
            {
                ans=i;
            }
        }
    }
    cout<<ans;
}
