#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}

int s2i(string s)
{
    int a;
    stringstream st;
    st<<s;
    st>>a;
    st.clear();
    return a;
}
map<int,int> m;
int main()
{
    int ans=0;
    string s="123456789";
    for(int i=0;i<f(9);i++)
    {
        if(i)
            next_permutation(s.begin(),s.end());
        int a=s2i(s.substr(0,2));
        int a1=s2i(s.substr(0,3));
        int b=s2i(s.substr(2,3));
        int b1=s2i(s.substr(3,2));
        int a3=s2i(s.substr(0,1));
        int a4=s2i(s.substr(0,4));
        int b3=s2i(s.substr(1,4));
        int b4=s2i(s.substr(4,1));
        int c=s2i(s.substr(5,4));
        //cout<<a<<' '<<b<<' '<<c<<'\n';
        if((a*b==c)||(a1*b1==c)||(a3*b3==c)||(a4*b4==c))
        {
            if(m[c]==1)
                continue;
            else
            {
                ans+=c;
                m[c]=1;
            }
        }
     
    }
    cout<<ans;
}
