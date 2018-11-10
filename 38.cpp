#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
unordered_set<ull> s;
ull s2i(string s)
{
    stringstream st;
    st<<s;
    ull x;
    st>>x;
    return x;
}
int main()
{
    ull ans=0;
    for(ull i=1;i<=1000000;i++)
    {
        s.clear();
        string tans;
        for(ull j=1;;j++)
        {
            ull tmp=i*j;
            tans=tans+to_string(i*j);
            while(tmp)
            {
                int tt=tmp%10;
                if(s.find(tt)!=s.end())
                    break;
                s.insert(tt);
                tmp/=10;
            }
            if(s.size()==9&&s.find(0)==s.end()&&!tmp)
            {
                cout<<tans<<'\n';
                ans=max(ans,s2i(tans));
                break;
            }
            if(tmp)
                break;
        }
    }
    cout<<ans;
}
