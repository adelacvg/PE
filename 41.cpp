#include<bits/stdc++.h>
using namespace std;
int fac(int n)
{
    int a=1;
    for(int i=1;i<=n;i++)
        a*=i;
    return a;
}
int s2i(string s)
{
    stringstream st;
    st<<s;
    int x;
    st>>x;
    return x;
}
int f(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int ans=0;
    string s="123";
    for(int i=4;i<=9;i++)
    {
        s+=to_string(i);
        cout<<s<<'\n';
        for(int j=1;j<=fac(i);j++)
        {
            if(f(s2i(s)))
                ans=max(ans,s2i(s));
            next_permutation(s.begin(),s.end());
        }
    }
    cout<<ans;
}
