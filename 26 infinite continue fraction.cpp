#include<bits/stdc++.h>
using namespace std;

string f(int num, int den)
{
    string res;
    map<int,int> m;
    m.clear();
    int rem = num%den;
    while(rem&&m.find(rem) == m.end())
    {
        m[rem] = res.length();
        rem *= 10;
        res += to_string(rem / den);
        rem %= den;
    }
    return (rem==0)?"":res.substr(m[rem]);
}

int main()
{
    string ss;
    int ans,mx=0;
    for(int i=1;i<=1000;i++)
    {
        ss=f(1,i);
        if(ss.length()>mx)
        {
            ans=i;
            int len = ss.length();
            mx=max(len,mx);
        }
    }
    cout<<ans;
}
