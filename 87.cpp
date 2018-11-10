#include<bits/stdc++.h>
using namespace std;
int flag[10100000];
vector<int> p;
set<int> s;
void sieve()
{
    for(int i=2;i<=10000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
        }
        for(long long int j=i*i;j<=10000;j+=i)
        {
            flag[j]=1;
        }
    }
}
int main()
{
    sieve();
    int ans=0;
    for(auto i:p)
    {
        if(i*i>=50000000)
            break;
        for(auto j:p)
        {
            if(i*i+j*j*j>=50000000)
                break;
            for(auto k : p)
            {
                if(i*i+j*j*j+k*k*k*k>=50000000)
                    break;
                if(i*i+j*j*j+k*k*k*k<50000000)
                    s.insert(i*i+j*j*j+k*k*k*k);
            }
        }
    }
    cout<<s.size();
}
