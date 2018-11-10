#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main()
{
    int ans=0;
    for(int i=1;i<1e6;i++)
    {
        for(int j=1;i*j<1e6;j++)
        {
            if((i+j)%4==0&&3*j>i&&(3*j-i)%4==0)
                m[i*j]++;
        }
    }
    for(auto i:m)
    {
        if(i.second==10)
            ans++;
    }
    cout<<ans;
}
