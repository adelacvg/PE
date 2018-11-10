#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<ull> p;
vector<bool> flag(10000010,0);
int main()
{
    for(ull i=2;i<=10000000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
            for(ull j=i*i;j<=10000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    ull ans=0;
    ull M=10000000;
    for(ull i=0;i<p.size();i++)
    {
        ull tans=0;
        if(p[i]*p[i]>M)
            break;
        for(ull j=i+1;j<p.size();j++)
        {
            tans=0;
            if(p[i]*p[j]>M)
            {
                break;
            }
            ull p1=p[i],p2=p[j];
            while(p1*p2<=M)
            {
                //tans=max(tans,p1*p2);
                while(p1*p2*p[j]<=M)
                    p2*=p[j];
                tans=max(tans,p1*p2);
                p1*=p[i];
                p2=p[j];
            }
            ans+=tans;
            //cout<<p[i]<<" "<<p[j]<<" "<<tans<<endl;
        }
    }
    cout<<ans<<endl;
}
