#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
int int_reverse(int x)
{
    stringstream st;
    string s;
    st<<x;
    st>>s;
    //cout<<s<<'\n';
    reverse(s.begin(),s.end());
    //cout<<s<<'\n';
    st.clear();
    st<<s;
    st>>x;
    st.str("");
    //cout<<x<<endl;
    return x;
}
int main()
{
    //int a=1011;
    //cout<<int_reverse(a)<<'\n';

    int ans=0;
    for(int i=100;i<=999;i++)
    {
        for(int j=i;j<=999;j++)
        {
            if(int_reverse(i*j)==i*j)
                ans=max(ans,i*j);
        }
    }
    cout<<ans;
}
