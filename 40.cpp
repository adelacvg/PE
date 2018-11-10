#include<bits/stdc++.h>
using namespace std;
int s2i(char s)
{
    stringstream st;
    st<<s;
    int x;
    st>>x;
    return x;
}
int main()
{
    string s="0";
    for(int i=1;i<=1000000;i++)
    {
        s+=to_string(i);
    }
    int ans=1;
    for(int i=1;i<=1000000;i*=10)
    {
        cout<<s[i]<<'\n';
        ans*=s2i(s[i]);
    }
    cout<<ans;
}
