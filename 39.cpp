#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
int main()
{
    int ans=0,tans=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=i;j<=1000;j++)
        {
            if(sqrt(i*i+j*j)==(int)sqrt(i*i+j*j))
            {
                int t = i+j+sqrt(i*i+j*j);
                m[t]++;
                if(m[t]>tans&&t<=1000)
                {
                    ans=t;
                    tans=m[t];
                }
            }
        }
    }
    cout<<ans;
}
