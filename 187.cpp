#include<bits/stdc++.h>
using namespace std;
vector<int> flag(100000010,0);
vector<unsigned long long> p;
int main()
{
    flag[0]=flag[1]=1;
    unsigned long long ans=0;
    for(unsigned long long i=2;i<100000000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
            for(unsigned long long j=i*i;j<100000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    int cnt=0;
    for(auto i:p)
    {
        if(i*i<100000000)
            cnt++;
        else
            break;
    }
    for(auto i: p)
    {
        for(auto j:p)
        {
            if(i*j<100000000)
            {
                ans++;
            }
            else
                break;
        }
    }
    cout<<(ans+cnt)/2;
}
