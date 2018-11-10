#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[10000010];
vector<int> p;
void sieve()
{
    for(ull i=2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
            for(ull j=i*i;j<=1000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
}
void solve()
{
    map<int,int> m;
    for(auto i:p)
    {
        m.clear();
        int t=i;
        int cnt=0;
        while(t)
        {
            m[t%10]++;
            if(m[t%10]==3)
            {
                for(int k=0;k<=9;k++)
                {
                    string s = to_string(i);
                    if(s[0]==('0'+t%10)&&k==0)
                        continue;
                    for(int j=0;j<s.size();j++)
                    {
                        if(s[j]==('0'+t%10))
                        {
                            s[j]=('0'+k);
                        }
                    }
                    if(!flag[stoi(s)])
                        cnt++;
                    if(cnt>=8)
                    {
                        cout<<i;
                        return;
                    }
                }
            }
            t/=10;
        }

    }
}
int main()
{
    sieve();
    solve();
}
