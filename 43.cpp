#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int d[10]={1,2,3,5,7,11,13,17};
int f(int n)
{
    int x=1;
    for(int i=1;i<=n;i++)
    {
        x*=i;
    }
    return x;
}
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
    string s="0123456789";
    for(int i=1;i<=f(10);i++)
    {
        int ff=1;
        for(int j=1;j<=7;j++)
        {
            if(s2i(s.substr(j,3))%d[j]!=0)
            {
                ff=0;
                break;
            }
        }
        if(ff)
            ans+=s2i(s);
        next_permutation(s.begin(),s.end());
    }
    cout<<ans;
}
